
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
	
	string path = this->util.getAppDataPath() + this->util.getClone();
	
	BOOL response = 0;
	CopyFile(filename,path.c_str(),response);
}