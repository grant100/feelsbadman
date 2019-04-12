#include "pch.h"
#include "PM.h"
#include <Windows.h>
#include <Psapi.h>

void PM::getProcesses() {
	DWORD aProcesses[1024];
	DWORD bNeeded;
	LPDWORD cProcesses;

	EnumProcesses(aProcesses, sizeof(aProcesses), &bNeeded);
	

}