using namespace std;
#pragma once
#include <string>
#include <windows.h>

/*
	Utility Module
	Responsible for maintaining and building the various directory paths for self deletion and copy 
*/

class UTIL {
	string path;
	string username;
	string base = "C:\\Users\\";
	string appData = "\\AppData";
	string clone = "\\clone.exe";

	char filename[MAX_PATH];
	void getModuleName();

	string currentDirectory;

public:
	char* getFileName();
	string getPath();
	string getBase();
	string getAppData();
	string getClone();
	string getUsername();
	string getAppDataPath();
	string getCurrentDirectory();
	bool isInAppData();
};