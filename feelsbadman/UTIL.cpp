#include "pch.h"
#include "UTIL.h"
#include <windows.h>

char* UTIL::getFileName() {
	getModuleName();
	return this->filename;
}

void UTIL::getModuleName() {
	GetModuleFileNameA(NULL, this->filename, MAX_PATH);
}