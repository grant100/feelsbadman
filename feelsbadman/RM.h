#pragma once
#include "UTIL.h"

#define REMOVE_COMAND TEXT("cmd.exe /C ping localhost -n 1 -w 3000 > nul & del /f /q \"%s\"")
class RM {
	char command[MAX_PATH * 2];
	STARTUPINFO info = { 0 };
	PROCESS_INFORMATION processInfo = { 0 };

	UTIL util;
public:
	void execute();
};