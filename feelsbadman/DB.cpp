#include "pch.h"
#include "DB.h"
#include <Windows.h>

void DB::execute() {
	this->alert();
}

void DB::alert() {
	if (this->isDebuggerPresent()) {
		MessageBox(NULL, "I caught you red-handed!", "I know what you're doing", NULL);
	}
}

BOOL DB::isDebuggerPresent() {
	return IsDebuggerPresent();
}