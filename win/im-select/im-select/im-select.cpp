

#include "stdafx.h"
#include <Windows.h>
#include <cstdlib>

using namespace std;

int getInputMethod() {
	HWND hwnd = GetForegroundWindow();
	if (hwnd) {
		DWORD threadID = GetWindowThreadProcessId(hwnd, NULL);
		HKL currentLayout = GetKeyboardLayout(threadID);
		unsigned int x = (unsigned int)currentLayout & 0x0000FFFF;
		return ((int)x);
	}
	return 0;
}

void switchInputMethod(int locale) {
	HWND hwnd = GetForegroundWindow();
	LPARAM currentLayout = ((LPARAM)locale);
	PostMessage(hwnd, WM_INPUTLANGCHANGEREQUEST, 0, currentLayout);
}

int main(int argc, char** argv)
{
	if (argc == 1) {
		int imID = getInputMethod();
		printf("%d\n", imID);
	} else {
		int locale = atoi(argv[1]);
		switchInputMethod(locale);
	}
	return 0;
}

