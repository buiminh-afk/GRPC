#include "krabs.hpp"
#include <iostream>
#include <thread>
#include <stdio.h>
#include <string>
#include <format>
#include "event.grpc.pb.h"
#include <grpc++/grpc++.h>

struct file {
	int opcode{};
	std::string opcode_name{};
	std::string filename{};
};

struct process {
	int opcode{};
	std::string opcode_name{};
	UINT32 pid;
	UINT32 ppid;
	std::string cmd_line{};
};

struct registry {
	int opcode{};
	std::string opcode_name{};
	INT64 init_time{};
	UINT32 status{};
	UINT32 index{};
	std::string key_name{};
};

const char i[] = "[!]";
const char e[] = "[-]";
const char s[] = "[+]";

std::vector<file> file_vector{};
std::vector<process> process_vector{};
std::vector<registry> registry_vector{};

std::string wchar_to_string(const wchar_t* wstr) {
	std::wstring ws(wstr);
	std::string str(ws.begin(), ws.end());
	return str;
}

void setup_file_io_provider(krabs::kernel::disk_file_io_provider& provider)
{
	provider.add_on_event_callback([](const EVENT_RECORD& record, const krabs::trace_context& trace_context) {
		std::set<int> valid_opcode{ 0, 32, 35, 36 };
		krabs::schema schema(record, trace_context.schema_locator);
		krabs::parser parser(schema);
		int event_opcode{ schema.event_opcode() };

		if (valid_opcode.find(event_opcode) != valid_opcode.end()) {
			std::wstring FileName = parser.parse<std::wstring>(L"FileName");

			file_vector.emplace_back(
				event_opcode,
				wchar_to_string(schema.opcode_name()),
				wchar_to_string(FileName.c_str())
			);
		}
		});
}

void setup_process_provider(krabs::kernel::process_provider& provider)
{
	provider.add_on_event_callback([](const EVENT_RECORD& record, const krabs::trace_context& trace_context) {
		std::set<int> valid_opcode{ 1, 2, 3, 4, 39 };
		krabs::schema schema(record, trace_context.schema_locator);
		krabs::parser parser(schema);
		int event_opcode{ schema.event_opcode() };
		if (valid_opcode.find(event_opcode) != valid_opcode.end()) {
			uint32_t ProcessId = parser.parse<uint32_t>(L"ProcessId");
			uint32_t ParentId = parser.parse<uint32_t>(L"ParentId");
			std::string imagefilename = parser.parse<std::string>(L"ImageFileName");
			std::wstring CommandLine = parser.parse<std::wstring>(L"CommandLine");

			process_vector.emplace_back(
				event_opcode,
				wchar_to_string(schema.opcode_name()),
				ProcessId,
				ParentId,
				wchar_to_string(CommandLine.c_str())
			);
		}
		});
}

void setup_registry_provider(krabs::kernel::registry_provider& provider)
{
	provider.add_on_event_callback([](const EVENT_RECORD& record, const krabs::trace_context& trace_context) {
		std::set<int> valid_opcode{ 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 };
		krabs::schema schema(record, trace_context.schema_locator);
		krabs::parser parser(schema);
		int event_opcode{ schema.event_opcode() };

		if (valid_opcode.find(event_opcode) != valid_opcode.end()) {
			int64_t InitialTime = parser.parse<int64_t>(L"InitialTime");
			uint32_t Status = parser.parse<uint32_t>(L"Status");
			uint32_t Index = parser.parse<uint32_t>(L"Index");
			std::wstring KeyName = parser.parse<std::wstring>(L"KeyName");

			registry_vector.emplace_back(
				event_opcode,
				wchar_to_string(schema.opcode_name()),
				InitialTime,
				Status,
				Index,
				wchar_to_string(KeyName.c_str())
			);
		}
		});
}

class EventInfo {
public:
	EventInfo(std::shared_ptr<grpc::Channel> channel) : _stub{ eventinfo::EventInfo::NewStub(channel) } {}
	void SendProcess(){
		grpc::ClientContext context{};
		eventinfo::ServerResponse response{};
		std::unique_ptr<grpc::ClientWriter<eventinfo::Process>> writer(_stub->ProcessEvent(&context, &response));

		while (!process_vector.empty()) {
			process top{ process_vector.front() };
			eventinfo::Process tmp{};
			tmp.set_opcode(top.opcode);
			tmp.set_opcode_name(top.opcode_name);
			tmp.set_pid(top.pid);
			tmp.set_ppid(top.ppid);
			tmp.set_cmd_line(top.cmd_line);

			process_vector.erase(process_vector.begin());
			if (!writer->Write(tmp)) {
				printf_s("%s failed to send process [%d] event to server\n", e, top.pid);
				break;
			}
		}

		writer->WritesDone();
		grpc::Status status = writer->Finish();

		if (status.ok()) {
			printf_s("%s server response: %s\n", s, response.msg().c_str());
		}
		else {
			printf_s("%s grpc call failed: %s\n", e, status.error_message().c_str());
		}
	}

	void SendRegistry() {
		grpc::ClientContext context{};
		eventinfo::ServerResponse response{};
		std::unique_ptr<grpc::ClientWriter<eventinfo::Registry>> writer(_stub->RegistryEvent(&context, &response));

		while (!registry_vector.empty()) {
			registry top{ registry_vector.front() };
			eventinfo::Registry tmp{};
			tmp.set_opcode(top.opcode);
			tmp.set_opcode_name(top.opcode_name);
			tmp.set_init_time(top.init_time);
			tmp.set_status(top.status);
			tmp.set_index(top.index);
			tmp.set_key_name(top.key_name);

			if (!writer->Write(tmp)) {
				printf_s("%s failed to send registry event to server\n", e);
				break;
			}

			registry_vector.erase(registry_vector.begin()); // Remove the processed event
		}

		writer->WritesDone();
		grpc::Status status = writer->Finish();

		if (status.ok()) {
			printf_s("%s server response: %s\n", s, response.msg().c_str());
		}
		else {
			printf_s("%s grpc call failed: %s\n", e, status.error_message().c_str());
		}
	}
	
	void SendFileIO() {
		grpc::ClientContext context{};
		eventinfo::ServerResponse response{};
		std::unique_ptr<grpc::ClientWriter<eventinfo::FileIO>> writer(_stub->FileIoEvent(&context, &response));

		while (!file_vector.empty()) {
			file top{ file_vector.front() };
			eventinfo::FileIO tmp{};
			tmp.set_opcode(top.opcode);
			tmp.set_opcode_name(top.opcode_name);
			tmp.set_filename(top.filename);

			if (!writer->Write(tmp)) {
				printf_s("%s failed to send file I/O event to server\n", e);
				break;
			}

			file_vector.erase(file_vector.begin()); 
		}

		writer->WritesDone();
		grpc::Status status = writer->Finish();

		if (status.ok()) {
			printf_s("%s server response: %s\n", s, response.msg().c_str());
		}
		else {
			printf_s("%s grpc call failed: %s\n", e, status.error_message().c_str());
		}
	}


private:
	std::unique_ptr<eventinfo::EventInfo::Stub> _stub;
};

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("%s usage: SystemInfo.exe <ServerIP> <ServerPort>\n", e);
		return EXIT_FAILURE;
	}

	std::string server_address{ std::format("{}:{}", argv[1], argv[2]) };

	printf("%s connecting to server %s\n", i, server_address.c_str());
	std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());

	EventInfo client{ channel };

	{
		krabs::kernel_trace kernel{ L"My kernel trace" };
		krabs::kernel::disk_file_io_provider file_io_provider;
		krabs::kernel::process_provider process_provider;
		krabs::kernel::registry_provider registry_provider;

		setup_file_io_provider(file_io_provider);
		setup_process_provider(process_provider);
		setup_registry_provider(registry_provider);

		kernel.enable(process_provider);
		kernel.enable(registry_provider);
		kernel.enable(file_io_provider);

		std::jthread kernel_thread([&kernel]() { kernel.start(); });

		Sleep(500);
		kernel.stop();
		printf_s("%s result: %llu file io events - %llu process events - %llu registry events\n",i, file_vector.size(), process_vector.size(), registry_vector.size());
	}
	std::jthread tProcess([&client]() {client.SendProcess(); });
	std::jthread tFileIO([&client]() {client.SendFileIO(); });
	std::jthread tRegistry([&client]() {client.SendRegistry(); });

	return EXIT_SUCCESS;
}
