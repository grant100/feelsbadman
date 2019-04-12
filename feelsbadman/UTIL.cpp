

#include "pch.h"
#include "UTIL.h"
#include <windows.h>
#include <Lmcons.h>
#include<algorithm>

string UTIL::getCurrentDirectory() {
	TCHAR buffer[MAX_PATH * 2];
	DWORD bLength = MAX_PATH;
	GetCurrentDirectory(bLength, buffer);
	this->currentDirectory = buffer;
	return this->currentDirectory;
}

string UTIL::getUsername() {
	TCHAR tcname[UNLEN + 1];
	DWORD length = UNLEN + 1;
	GetUserName(tcname, &length);
	this->username = tcname;
	return this->username;
}

string UTIL::getClone() {
	return this->clone;
}

string UTIL::getAppData() {
	return this->appData;
}

string UTIL::getBase() {
	return this->base;
}

string UTIL::getPath() {
	return this->path;
}
char* UTIL::getFileName() {
	this->getModuleName();
	return this->filename;
}

string UTIL::getAppDataPath() {
	return this->getBase() + this->getUsername() + this->getAppData();
}

void UTIL::getModuleName() {
	GetModuleFileNameA(NULL, this->filename, MAX_PATH);
}

void UTIL::getModuleNameB() {
	GetModuleFileNameA(NULL, this->filename, MAX_PATH);
}

bool UTIL::isExecutingFromAppData() {
	this->getModuleName();
	string path = this->getAppDataPath() + this->getClone();
	string dire = this->filename;

	std::transform(path.begin(), path.end(), path.begin(),::tolower);
	std::transform(dire.begin(), dire.end(), dire.begin(), ::tolower);
	bool same = path == dire;
	if (same) {
		printf("%s Directory: %s \nPath: %s \n", "TRUE", dire.c_str(), path.c_str());
	}
	else {
		printf("%s Directory: %s \nPath: %s \n", "FALSE", dire.c_str(), path.c_str());
	}
	
	return path == dire;
}