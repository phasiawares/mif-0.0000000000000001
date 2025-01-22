typedef struct IUnknown IUnknown;
#pragma once

#include "mif.h"

// Width and height
int w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN);

DWORD WINAPI ProximePayload(LPVOID lpvd)
{
		HDC hdc = GetDC(0);
		while (true) {
			for (FLOAT angle = 0.f; angle < 361.f; angle++) {
				INT lx = 900 * cos(angle * M_PI / 900), ly = 900 * sin(angle * M_PI / 900);
				StretchBlt(hdc, lx / 2, ly / 2, w - lx, h - ly, hdc, 0, 0, w, h, SRCINVERT);
				Sleep(10);
			}
		}
		ReleaseDC(0, hdc);
}
