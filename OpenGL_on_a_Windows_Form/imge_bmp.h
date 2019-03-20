#pragma once

#include <Windows.h>


BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile);

BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height);

bool  SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);

BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long* newsize);