#include "StaticLib.h"
#include <sddl.h> 
#include <psapi.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <format>

#pragma comment (lib,"Version.lib")

std::string wcharToString(const wchar_t* wstr) {
	if (wstr == nullptr) {
		return "";
	}

	int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);

	std::string str(size_needed, 0);

	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, &str[0], size_needed, NULL, NULL);

	return str;
}

std::string getProcessUsername(HANDLE hProcess)
{
	if (hProcess == NULL) {
		return {};
	}

	std::wstring endUser = L"";
	std::wstring endDomain = L"";

	HANDLE hToken = NULL;

	if (OpenProcessToken(hProcess, TOKEN_QUERY, &hToken))
	{
		DWORD tokenSize = 0;
		GetTokenInformation(hToken, TokenUser, NULL, 0, &tokenSize);

		if (tokenSize > 0)
		{
			BYTE* data = new BYTE[tokenSize];
			if (GetTokenInformation(hToken, TokenUser, data, tokenSize, &tokenSize))
			{
				TOKEN_USER* pUser = (TOKEN_USER*)data;
				PSID pSID = pUser->User.Sid;

				DWORD userSize = 0;
				DWORD domainSize = 0;
				SID_NAME_USE sidName;

				// First call to get buffer sizes
				LookupAccountSid(NULL, pSID, NULL, &userSize, NULL, &domainSize, &sidName);
				wchar_t* user = new wchar_t[userSize + 1];
				wchar_t* domain = new wchar_t[domainSize + 1];

				// Second call to actually retrieve the account name
				if (LookupAccountSid(NULL, pSID, user, &userSize, domain, &domainSize, &sidName))
				{
					user[userSize] = L'\0';
					domain[domainSize] = L'\0';
					endUser = user;
					endDomain = domain;
				}

				delete[] domain;
				delete[] user;
			}

			delete[] data;
		}

		CloseHandle(hToken);
	}

	if (!endUser.empty()) {
		std::wstring fullName = endDomain + L"\\" + endUser;
		return wcharToString(fullName.c_str());
	}

	return "";
}

std::string getCompanyName(HANDLE hProcess) {
	WCHAR processPath[MAX_PATH] = { 0 };
	DWORD pathSize = MAX_PATH;

	// Get the full path of the executable
	if (!QueryFullProcessImageNameW(hProcess, 0, processPath, &pathSize)) {
		return "Failed to get process image path";
	}

	// Get the size of the version information
	DWORD handle;
	DWORD verSize = ::GetFileVersionInfoSizeW(processPath, &handle);
	if (verSize == 0) {
		return "Failed to get version info size";
	}

	// Allocate buffer to hold version information
	std::vector<BYTE> verData(verSize);

	// Get the version information
	if (!::GetFileVersionInfoW(processPath, handle, verSize, verData.data())) {
		return "Failed to get version info";
	}

	// Query the company name
	LPVOID lpBuffer = nullptr;
	UINT size = 0;
	if (::VerQueryValueW(verData.data(), L"\\StringFileInfo\\040904b0\\CompanyName", &lpBuffer, &size) && size > 0) {
		// Convert the wide string (company name) to a narrow string (std::string)
		wchar_t* companyNameW = static_cast<wchar_t*>(lpBuffer);
		return wcharToString(companyNameW);
	}
	else {
		return "Company name not found";
	}
}

std::string getProcessImage(HANDLE hProcess) {
	DWORD path_size = MAX_PATH;
	CHAR path[MAX_PATH] = {};

	if (::QueryFullProcessImageNameA(hProcess, 0, path, &path_size)) {
		return std::string(path);
	}
	else {
		return std::format("Failed to get process image path ({})", ::GetLastError());
	}
}

std::string getProcessType(HANDLE hProcess) {
	DWORD priority = ::GetPriorityClass(hProcess);
	std::string buffer{};
	if (priority == 0) {
		buffer = std::format("Unknown process type ({})", ::GetLastError());
		return buffer;
	}

	if (priority == IDLE_PRIORITY_CLASS) {
		buffer = std::format("Background Process");
	}
	else if (priority == HIGH_PRIORITY_CLASS || priority == REALTIME_PRIORITY_CLASS) {
		buffer = std::format("System Process");
	}
	else {
		buffer = std::format("App Process");
	}

	return buffer;
}

void getMemoryInfo(HANDLE hProcess, SystemLib::process* tmp) {
	PROCESS_MEMORY_COUNTERS_EX pmc{};

	if (::GetProcessMemoryInfo(hProcess, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
		tmp->private_bytes = pmc.PrivateUsage;
		tmp->working_set = pmc.WorkingSetSize;
		tmp->virtual_bytes = pmc.PagefileUsage;
	}
}

SystemLib::process getProcessInfo(PROCESSENTRY32 pe32) {
	HANDLE hProcess{};
	SystemLib::process tmp{};
	hProcess = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pe32.th32ProcessID);
	if (hProcess != NULL) {
		tmp.exefile = wcharToString(pe32.szExeFile);
		tmp.path = getProcessImage(hProcess);
		tmp.process_type = getProcessType(hProcess);
		tmp.pid = pe32.th32ProcessID;
		tmp.company = getCompanyName(hProcess);
		getMemoryInfo(hProcess, &tmp);
		tmp.username = getProcessUsername(hProcess);
		::CloseHandle(hProcess);
	}
	return tmp;
}

std::vector<SystemLib::process> SystemLib::ListAllProcesses(){
	HANDLE hSnapshot{};
	std::vector<SystemLib::process> process_list{};

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE) {
		printf_s("Failed to create process snapshot (%ld)\n", GetLastError());
		goto CLEANUP;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!::Process32First(hSnapshot, &pe32)) {
		printf_s("Failed to retrieve the first process (%ld)\n", GetLastError());
		goto CLEANUP;
	}

	// Loop through all processes and print their PIDs
	do {
		process_list.push_back(getProcessInfo(pe32));
	} while (::Process32Next(hSnapshot, &pe32));
	goto CLEANUP;

CLEANUP:
	if (hSnapshot != NULL) {
		::CloseHandle(hSnapshot);
	}
	return process_list;
}

