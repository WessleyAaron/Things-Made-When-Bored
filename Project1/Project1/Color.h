#include <Windows.h>
#include <iostream>

int color(int constColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), constColor);

	return 0;
}