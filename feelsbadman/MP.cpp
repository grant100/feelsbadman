#include "pch.h"
#include "MP.h"
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>

void  MP::execute()
{
	HANDLE hProcessSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);

	PROCESSENTRY32 ProcessEntry = { 0 };
	ProcessEntry.dwSize = sizeof(ProcessEntry);

	BOOL status = FALSE;
	status = Process32First(hProcessSnapShot, &ProcessEntry);

	if (!status)
	{
		return;
	}

	do
	{
		int value = _tcsicmp(ProcessEntry.szExeFile, _T("mspaint.exe"));
		if (value == 0)
		{
			MessageBox(NULL, "No Time to Paint.", "Uh Oh!", NULL);
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, ProcessEntry.th32ProcessID);
			TerminateProcess(hProcess, 0);
			CloseHandle(hProcess);

		}

	} while (Process32Next(hProcessSnapShot, &ProcessEntry));

	CloseHandle(hProcessSnapShot);
}