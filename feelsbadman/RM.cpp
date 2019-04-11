#include "pch.h"
#include "RM.h"
#include <Windows.h>
#include <strsafe.h>

void RM::execute(){
	char* filename = this->util.getFileName();
	StringCbPrintf(this->command, 2 * MAX_PATH, REMOVE_COMAND, filename);
	CreateProcess(NULL, this->command, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &this->info, &this->processInfo);
	CloseHandle(this->processInfo.hThread);
	CloseHandle(this->processInfo.hProcess);
}