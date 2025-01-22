typedef struct IUnknown IUnknown;
#pragma once

#include "mif.h"

#define PI 3.14159265358979

typedef struct {
	float x;
	float y;
	float z;
} POINT3D, *PPOINT3D;

POINT3D RotatePoints(POINT3D point, float fx, float fy, float fz) {
	float cx = cos(fx), sx = sin(fx);
	float cy = cos(fy), sy = sin(fy);
	float cz = cos(fz), sz = sin(fz);
	
	float y = point.y * cx - point.z * sx;
	float z = point.y * sx - point.z * cx;
	point.y = y;
	point.z =z;
	float x = point.x * cy + point.z * sy;
	z = -point.x * sy + point.z * cy;
	point.x = x;
	point.z = z;
	x = point.x * cz - point.y * sz;
	y = point.x * sz + point.y * cz;
	point.x = x;
	point.y = y;
	
	return point;
}

DWORD WINAPI DrawCube(HDC hdc, POINT3D p3dCenter, float s, float fx, float fy, float fz) {
	POINT3D verts[] = {
		-s, -s, -s,
		s, -s, -s,
		s, s, -s,
		-s, s, -s,
		-s, -s, s,
		s, -s, s,
		s, s, s,
		-s, s, s
	};
	
	POINT spt[8];
	
	for (int t = 0; t < 8; t++) {
		POINT3D rotpoint = RotatePoints(verts[t], fx, fy, fz);
		int sx = static_cast<int>(p3dCenter.x + rotpoint.x),
		sy = static_cast<int>(p3dCenter.y + rotpoint.y);
		spt[t].x = sx;
		spt[t].y = sy;
		DrawIcon(hdc, sx, sy, LoadCursorA(NULL, IDC_WAIT));
	}
	
	POINT opt1[5] = {spt[0], spt[1], spt[2], spt[3], spt[0]};
	Polyline(hdc, opt1, 5);
	
	POINT opt2[5] = {spt[4], spt[5], spt[6], spt[7], spt[4]};
	Polyline(hdc, opt2, 5);
	
	POINT clpt[8] = {
		spt[0], spt[4], spt[1], spt[5],
		spt[2], spt[6], spt[3], spt[7]
	};
	Polyline(hdc, &clpt[0], 2);
	Polyline(hdc, &clpt[2], 2);
	Polyline(hdc, &clpt[4], 2);
	Polyline(hdc, &clpt[6], 2);
}

int signx = 1, signy = 1, signxcopy = 1, signycopy = 1;
int increment = 10;
float x = 10, y = 10;
