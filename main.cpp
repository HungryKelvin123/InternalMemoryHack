#include <Windows.h>

bool firstInjectMessage = true;
bool notPrinted = true;

void injectedThread() {
	Sleep(2000);
	while (true) {
		HWND hwnd = FindWindow(NULL, L"The Battle For Wesnoth - 1.14.9");

		if (hwnd == NULL) {
			if (firstInjectMessage) {
				MessageBox(NULL, L"Game Not Found, Close Process", L"Error", MB_OK);
				firstInjectMessage = false;
			}
		}
		else {
			if (firstInjectMessage) {
				MessageBox(hwnd, L"Cheat injected", L"InternalMemoryHack", MB_OK);
				firstInjectMessage = false;
			}
			if (GetAsyncKeyState(VK_RSHIFT) & 0x8000) {
				DWORD* playerBase = (DWORD*)0x017EED18;
				DWORD* gameBase = (DWORD*)(*playerBase + 0xA90);
				DWORD* goldValue = (DWORD*)(*gameBase + 4);
				if (!IsBadWritePtr(goldValue, sizeof(DWORD))) {
					*goldValue = 999999;
					if (notPrinted) {
					MessageBox(hwnd, L"Gold set", L"InternalMemoryHack", MB_OK);
					notPrinted = false;
				}
				notPrinted = true;
				}
				else {
					MessageBox(hwnd, L"Join a game, gold value not found", L"Error", MB_OK);
				}

				
			}
		}
		Sleep(100);
	}
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)injectedThread, NULL, 0, NULL);
	}

	return true;
}