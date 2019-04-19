#ifndef KEYBOARD_HOOK_H
#define KEYBOARD_HOOK_H
#pragma once
#include <Windows.h>

HHOOK hook;

LRESULT KeyboardHookProc(int code, WPARAM wParam, LPARAM lParam) {
	KBDLLHOOKSTRUCT kbdStruct;
	if (code >= 0) {
		if (wParam == WM_KEYDOWN) {
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			if (kbdStruct.vkCode == VK_ESCAPE) {
				MessageBox(NULL, "Escape Pressed", "Key Pressed", NULL);
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


