#pragma once
#include <Windows.h>
#include <string>
#include <vector>

namespace SystemLib {
	struct process {
		DWORD pid;
		std::string path{};
		std::string exefile{};
		std::string process_type{};
		std::string company{};
		std::string username{};
		SIZE_T private_bytes{}, working_set{}, virtual_bytes{};
	};

	std::vector<SystemLib::process> ListAllProcesses();
}