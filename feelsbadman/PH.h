using namespace std;
#pragma once
#include<string>
#include "UTIL.h"
/**
	Process Hacking module:
	Responsible for detecting running processes
**/
class PH {
	UTIL util;

public:
	string x64dbg = "x64dbg.exe";
	string x32dbg = "x32dbg.exe";
	string Proc32 = "Procmon.exe";
	string ida64 = "ida64.exe";

	bool isDlexe = false;
	bool isx64dbg = false;
	bool isx32dbg = false;
	bool isProc32 = false;
	bool isida64 = false;
	bool isDetected();
	bool isDownloadedDetected();
	void detectProcesses();
};