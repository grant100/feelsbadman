
#include "pch.h"
#include "PM.h"
#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include <TlHelp32.h>

bool PM::getProcesses() {
	/*
Function takes in a string value for the process it is looking for like ST3Monitor.exe
then loops through all of the processes that are currently running on windows.
If the process is found it is running, therefore the function returns true.
*/
	std::string process = "x64dbg.exe";
	std::string compare;
	bool procRunning = false;

	HANDLE hProcessSnap;
	PROCESSENTRY32 pe32;
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap == INVALID_HANDLE_VALUE) {
		procRunning = false;
	}
	else {
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hProcessSnap, &pe32)) { // Gets first running process
			if (pe32.szExeFile == process) {
				procRunning = true;
			}
			else {
				// loop through all running processes looking for process
				while (Process32Next(hProcessSnap, &pe32)) {
					// Set to an AnsiString instead of Char[] to make compare easier
					
					compare = pe32.szExeFile;
					
					if (compare == process) {
						// if found process is running, set to true and break from loop
						procRunning = true;
						break;
					}
				}
			}
			// clean the snapshot object
			CloseHandle(hProcessSnap);
		}
	}

	return procRunning;
/*	DWORD pids[1024], cb;
	EnumProcesses(pids, sizeof(pids), &cb);

	DWORD count = cb / sizeof(DWORD);
	TCHAR name[MAX_PATH];
	for (unsigned int i = 0; i < count; i++) {
		
		HMODULE hMod;
		DWORD cb2;
		HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pids[i]);
		if (hProcess != NULL) {
			if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cb2)) {
				GetModuleBaseNameA(hProcess, hMod, name, sizeof(name) / sizeof(TCHAR));
				std::cout << name;
				if (name == "x64dbg.exe" || name == "ida64.exe" || name == "x32dbg.exe" || name == "Procmon.exe" || name == "Procmon64.exe") {
					return TRUE;
				}
			}
		}
	}
	return FALSE;*/
}
/*
void PM::hasProcesses() {
	getProcesses();
	DWORD count = this->bNeeded / sizeof(DWORD);
	for (int i = 0; i < count; i++) {
		if (this->processIds[i] != 0) {
			LPSTR name;
			HMODULE hMod;
			DWORD cb;
			HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, this->processIds[i]);
			if (hProcess != NULL) {
				if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cb)) {
					GetModuleBaseName(hProcess, hMod, name, sizeof(name)/ sizeof(WCHAR) );
				}
			}
		}
		
	}
}*/