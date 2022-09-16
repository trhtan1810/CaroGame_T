#pragma once
#include <Windows.h>
static void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
class _Common
{
public :
	static void CoDinhConsole();
	// Cố định màn hình Console
	static void TaoConsole(int w, int h);
	// Chỉnh size của màn hình Console 
public:
	_Common();
	~_Common();
};

