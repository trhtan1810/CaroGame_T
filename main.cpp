#include "_Point.h"
#include "_Board.h"
#include "_Common.h"
#include "_Game.h"
#include "_Play.h"
#include <string.h>

int main()
{
	int n = 100;
	_Common::CoDinhConsole();
	_Common::TaoConsole(1000, 600);
	MENU(n);
	system("pause");
}