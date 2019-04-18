using namespace std;
#pragma once
#include "UTIL.h"
#include <string>
#include <Lmcons.h>

/**
	Copy Module:
	Responsible for copying executable to user AppData
**/
class CP {
	UTIL util;
public:
	void copy();
	void start();
	void execute();
};