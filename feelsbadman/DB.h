#pragma once
#include<windows.h>

class DB {
public:
	void execute();
	void alert();
	BOOL isDebuggerPresent();
};