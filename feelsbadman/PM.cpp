
#include "pch.h"
#include "PM.h"
#include <Windows.h>
#include <Psapi.h>
#include <iostream>
bool PM::getProcesses() {
	DWORD pids[1024], cb;
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
	return FALSE;
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