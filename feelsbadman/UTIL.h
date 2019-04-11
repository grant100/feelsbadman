using namespace std;
#pragma once
#include <string>
#include <windows.h>

class UTIL {
	char filename[MAX_PATH];
	void getModuleName();
public:
	char* getFileName();
};