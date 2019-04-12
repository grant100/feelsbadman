using namespace std;
#pragma once
#include "pch.h"
#include "UTIL.h"
#include <string>
#include <Lmcons.h>

/**
	Copy Module:
	Responsible for copying executable to user AppData
**/
#define START_PROCESS TEXT("cmd.exe /C %s")
class CP {
	char command[MAX_PATH * 2];
	STARTUPINFO info = { 0 };
	PROCESS_INFORMATION processInfo = { 0 };

	UTIL util;

public:
	void copy();
	void start();
	void execute();
};