#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <format>
#include "info.grpc.pb.h"
#include <grpc++/grpc++.h>
#include "StaticLib.h"

const char i[] = "[!]";
const char e[] = "[-]";
const char s[] = "[+]";

class SystemInfo {
public:
	SystemInfo(std::shared_ptr<grpc::Channel> channel) : _stub{ sysinfo::SystemInfo::NewStub(channel) } {}

	void SendProcess(std::vector<SystemLib::process> process_list) {
		grpc::ClientContext context{};
		sysinfo::ServerResponse response{};

		std::unique_ptr<grpc::ClientWriter<sysinfo::Process>> writer(_stub->Processes(&context, &response));
		printf("%s sending processes to server\n", i);

		for (auto& process : process_list) {
			sysinfo::Process tmp{};
			tmp.set_pid(process.pid);
			tmp.set_path(process.path);
			tmp.set_exefile(process.exefile);
			tmp.set_process_type(process.process_type);
			tmp.set_company(process.company);
			tmp.set_username(process.username);
			tmp.set_private_bytes(process.private_bytes);
			tmp.set_working_set(process.working_set);
			tmp.set_virtual_bytes(process.virtual_bytes);

			writer->Write(tmp);
		}

		writer->WritesDone();

		grpc::Status status = writer->Finish();

		if (status.ok()) {
			printf("%s send processes to server successfully\n", s);
		}
		else {
			printf("%s send processes to server failed\n", e);
		}
	}
private:
	std::unique_ptr<sysinfo::SystemInfo::Stub> _stub;
};

int main(int argc, char* argv[]) {

	if (argc != 3) {
		printf("%s usage: SystemInfo.exe <ServerIP> <ServerPort>\n", e);
		return EXIT_FAILURE;
	}

	std::string server_address{ std::format("{}:{}", argv[1], argv[2]) };

	printf("%s connecting to server %s\n", i, server_address.c_str());

	std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
	grpc_connectivity_state state = channel->GetState(true);

	SystemInfo client{ channel };
	auto process_list = SystemLib::ListAllProcesses();
	client.SendProcess(process_list);

	/*if (state == GRPC_CHANNEL_READY) {
		printf_s("%s connected to server\n", s);
		
	}
	else {
		printf_s("%s can not connect to server\n", e);
	}*/

	return EXIT_SUCCESS;
}
