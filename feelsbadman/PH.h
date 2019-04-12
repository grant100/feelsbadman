using namespace std;
#pragma once
#include<string>

class PH {
	string x64dbg = "x64dbg.exe";
	string x32dbg = "x32dbg.exe";
	string Proc32 = "Procmon.exe";
	string ida64 = "ida64.exe";

	bool isx64dbg = false;
	bool isx32dbg = false;
	bool isProc32 = false;
	bool isida64 = false;

public:
	//PH();
	void hasProcesses();
	//void hasProcesses();
};