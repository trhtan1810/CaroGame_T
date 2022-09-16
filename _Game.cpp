#include "_Game.h"

_Game::_Game(int pSize, int pLeft, int  pTop)
{
	_b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1;
	_x = pLeft;
	_y = pTop;
}
int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard()
{
	_command = toupper(_getch());
	return _command;
}

void _Game::startGame()
{
	system("cls");
	_b->resetData();
	_b->drawBoard();
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
	if (_turn == 1)
	{
		Textcolor(Blue);
		gotoxy(SIZE * 4 + 42, 8);
		cout << " Den luot PLAYER 1 ";
	}
	else
	{
		Textcolor(Red);
		gotoxy(SIZE * 4 + 42, 8);
		cout << " Den luot PLAYER 2 ";
	}

}

void _Game::exitGame()
{
	_loop = false;
}
void _Game::moveRight()
{
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		_x += 4;
		gotoxy(_x, _y);
	}
}

void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0))
	{
		_x -= 4;
		gotoxy(_x, _y);
	}
}
void P1WIN()
{
	AnTroChuot();
	int check = 1;
	P1();
	Box();
}
void P2WIN()
{
	AnTroChuot();
	int check = 1;
	P2();
	Box();
}
void PDraw()
{
	AnTroChuot();
	int check = 1;
	Draw();
	Box();
}
void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		_y += 2;
		gotoxy(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0))
	{
		_y -= 2;
		gotoxy(_x, _y);
	}
}
bool _Game::processCheckBoard()
{
	switch (_b->checkBoard(_x, _y, _turn))
	{
	case -1:
		Textcolor(Blue);
		cout << "X";
		Textcolor(Red);
		gotoxy(SIZE * 4 + 42, 8);
		cout << " Den luot PLAYER 2 ";
		gotoxy(_x, _y);
		break;
	case 1:
		Textcolor(Red);
		cout << "O";
		Textcolor(Blue);
		gotoxy(SIZE * 4 + 42, 8);
		cout << " Den luot PLAYER 1 ";
		break;
	case 0:
		return false;
		break;
	}
	return true;
}
int _Game::DemNuocCoDaDi()
{
	return _b->CountX + _b->CountY;
}
void P1()
{
	Textcolor(Blue);
	gotoxy(SIZE * 4 + 43, 15);
	cout << "P1 WIN.";
}
void P2()
{
	Textcolor(Red);
	gotoxy(SIZE * 4 + 43, 15);
	cout << "P2 WIN.";

}
void Draw()
{
	Textcolor(Yellow);
	gotoxy(SIZE * 4 + 43, 15);
	cout << "DRAW.";
}
void Box()
{
	Textcolor(DarkYellow);
	gotoxy(SIZE * 4 + 43, 17);
	cout << "Y   : Play Again";
}
int _Game::KiemTraKetThuc(int x, int y)
{
	gotoxy(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int pWhoWin = _b->testBoard(x, y);
	switch (pWhoWin)
	{
	case -1:
		P1WIN();
		break;
	case 1:
		P2WIN();
		break;
	
		PDraw();
		break;
	case 2:
		_turn = !_turn;
	}
	gotoxy(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
int _Game::getXatEnter()
{
	return _x;
}
int _Game::getYatEnter()
{
	return _y;
}
void _Game::TimKiemNuocDi1()
{
	_x = _b->Tim_Kiem_NuocDi_1().getX();
	_y = _b->Tim_Kiem_NuocDi_1().getY();
}
void _Game::TimKiemNuocDi2()
{
	_x = _b->Tim_Kiem_NuocDi_2().getX();
	_y = _b->Tim_Kiem_NuocDi_2().getY();
}
void _Game::TimKiemNuocDi3()
{
	_x = _b->Tim_Kiem_NuocDi_3().getX();
	_y = _b->Tim_Kiem_NuocDi_3().getY();
}
_Game::~_Game()
{
	delete _b;
}
void _Game::SaveGame(int n)
{
	char data[30];
	ofstream f1;
	ofstream f2;
	gotoxy(20, 25);
	cout << "ENTER FILE NAME: ";
	Textcolor(Cyan);
	cin.getline(data, 30);
	f1.open(data, ios::out);
	f2.open("Name.txt", ios::app);
	f2 << data << " " << endl;
	//thong tin
	f1 << scorep1 << " " << scorep2 << " " << n << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			f1 << _b->get_Check(i, j) << " ";
		}
		f1 << endl;
	}
	f1.close();
	f2.close();
	gotoxy(20, 27);
	cout << "ESC : BACK";
	int t = 1;
	while (t)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 27:
				t = 0;
				system("cls");
				MENU(99);
				break;
			}
		}
	}
}
void _Game::LoadGame(char data[30])
{

	//NHAP FILE
	ifstream f;
	f.open(data, ios::in);
	if (!f) {
		gotoxy(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
	}
	else
	{
		f >> scorep1 >> scorep2 >> chedo;
		system("cls");
		//thong tin
		//ban co
		int k;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				f >> k;
				_b->loadData(i, j, k);
			}
		}
		_x = _b->getXAt(0, 0);
		_y = _b->getYAt(0, 0);
		_b->drawBoard();
		f.close();
	}
	if (_turn == 1)
	{
		Textcolor(Blue);
		gotoxy(SIZE * 4 + 42, 8);
		cout << " Den luot PLAYER 1 ";
	}
	else
	{
		Textcolor(Red);
		gotoxy(SIZE * 4 + 42, 8);
		cout << " Den luot PLAYER 2 ";
	}

}
