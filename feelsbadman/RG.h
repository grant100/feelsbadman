#pragma once
#include "UTIL.h"
#include <winreg.h>
/**
	Registry Module:
	Responsible for setting registry RUN key
**/

class RG {
	UTIL util;
public:
	void execute();
	bool isValueExisting(HKEY hKey);
};