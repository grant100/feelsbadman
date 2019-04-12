
#include "pch.h"
#include "PH.h"
#include <Windows.h>
#include <tlhelp32.h>

void PH::hasProcesses() {

	string compare;
	bool procRunning = false;

	HANDLE hProcessSnap;
	PROCESSENTRY32 pe32;
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, false);

	pe32.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hProcessSnap, &pe32)) {
		while (Process32Next(hProcessSnap, &pe32)) {
			if (pe32.szExeFile == this->x64dbg) {
				isx64dbg = true;
			}

			if (pe32.szExeFile == this->x32dbg) {
				isx32dbg = true;
			}

			if (pe32.szExeFile == this->Proc32) {
				isProc32 = true;
			}	

			if (pe32.szExeFile == this->ida64) {
				isida64 = true;
			}
		}

		CloseHandle(hProcessSnap);
	}
}
