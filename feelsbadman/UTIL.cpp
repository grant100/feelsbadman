#include "pch.h"
#include "UTIL.h"
#include <windows.h>
#include <Lmcons.h>


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
	return getBase() + getUsername() + getAppData();
}

void UTIL::getModuleName() {
	GetModuleFileNameA(NULL, this->filename, MAX_PATH);
}

bool UTIL::isInAppData() {
	string path = this->getAppDataPath();
	string dire = this->getCurrentDirectory();
	return path == dire;
}