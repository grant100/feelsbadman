using namespace std;
#pragma once
#include "pch.h"
#include "UTIL.h"
#include <string>
#include <Lmcons.h>

class CP {
	string path;
	string base = "C:\\Users\\";
	string appData = "\\AppData";
	string clone = "\\clone.exe";

	UTIL util;

public:
	void copy();
	void execute();
};