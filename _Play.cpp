#include "_Play.h"
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
using namespace std;
struct Name {
	char data[30];
};
vector <Name> ch;

void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
void AnTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
int ReadChedo(char a[30])
{
	int d1, d2, chedo;
	system("cls");
	ifstream f;
	f.open(a, ios::in);
	if (!f) {
		gotoxy(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
		Sleep(1000);
		MENU(99);
	}
	else
		f >> d1 >> d2 >> chedo;
	f.close();
	return chedo;
}
void ReadNameFile()
{
	Textcolor(Cyan);
	gotoxy(20, 2);
	cout << "LIST FILE NAME";
	int i = 4;
	ifstream f;
	f.open("Name.txt", ios::in);
	while (!f.eof())
	{
		char s[30];
		f >> s;
		gotoxy(20, i);
		cout << s;
		i++;
	}
	f.close();
}
void LoadLoad()
{
	int n = 100;
	system("cls");
	ReadNameFile();
	char data[30];
	HienTroChuot();
	gotoxy(50, 2);
	cout << "ENTER FILE NAME: ";
	cin.getline(data, 30);
	int chedo = ReadChedo(data);
	if (chedo == -30 || chedo == -31)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = PlayerVsPlayer(a, chedo, data);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
	}
	if (chedo == -3)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = PlayerVsCom1(a, -3, data);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
	}
	if (chedo == -4)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = PlayerVsCom2(a, -4, data);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
	}
	if (chedo == -5)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = PlayerVsCom3(a, -5, data);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
	}
}

void Help()
{
	system("cls");
	Textcolor(Cyan);
	gotoxy(20, 8);
	cout << "================================== HELP ======================================";
	gotoxy(20, 11);
	cout << "HUONG DAN" << endl;
	gotoxy(20, 13);
	cout << "1. Ban co gom 10x10 o vuong." << endl;
	gotoxy(20, 15);
	cout << "2. Su dung cac phim W A S D de di chuyen va Enter de danh." << endl;
	gotoxy(20, 17);
	cout << "3. Luat choi cu du 4 quan co X hoac O theo hang ngang, doc, cheo se chien thang." << endl;
	gotoxy(20, 19);
	cout << "4. Luat choi tuan theo quy dinh chan 2 dau " << endl;

	gotoxy(20, 21);
	cout << "-> Chuc moi nguoi choi game vui ve !!" << endl;
	gotoxy(20, 24);
	cout << "BACK";
	char command = ' ';
	command = _getch();
	system("cls");
}

void MENU(int n)
{
	
	AnTroChuot();
	int x = 20, y = 0;
	int i;
	char s[30] = " ";
	int check = 1;
	
	Textcolor(DarkYellow);
	gotoxy(20, 2); cout << "*--------";
	Textcolor(7);
	cout << "MAIN MENU";
	Textcolor(DarkYellow);
	cout << "--------*";
	Textcolor(Red);
	gotoxy(20, 4); cout << "Press number to choice";
	Textcolor(7);
	gotoxy(20, 6); cout << "1. Player Vs Player";
	gotoxy(20, 8); cout << "2. Player Vs Computer (Easy)";
	gotoxy(20, 10); cout << "3. Player Vs Computer (Normal)";
	gotoxy(20, 12); cout << "4. Player Vs Computer (Hard)";
	gotoxy(20, 14); cout << "5. Watch Replay Game";
	gotoxy(20, 16); cout << "6. Help";
	gotoxy(20, 18); cout << "7. Exit";

	
	while (check)
	{
		int t;
		Diem a;
		switch (_getch())
		{

		case '1':


		{a.score1 = 0;
		a.score2 = 0;
		t = PlayerVsPlayer(a, 0, s);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
		break;}
		case '2':

		{a.score1 = 0;
		a.score2 = 0;
		t = PlayerVsCom1(a, 0, s);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
		break;}
		case '3':

		{a.score1 = 0;
		a.score2 = 0;
		t = PlayerVsCom2(a, 0, s);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
		break;}

		case '4':

		{a.score1 = 0;
		a.score2 = 0;
		t = PlayerVsCom3(a, 0, s);
		if (t == 27)
		{
			system("cls");
			MENU(99);
		}
		break;}
		case '5':
		{LoadLoad();
		MENU(99);
		break;}

		case '6':
		{Help();
		MENU(99);
		break;}

		case '7':
		{exit(0);
		break;}
		}
	}
}
void Display()
{
	Textcolor(Blue);
	gotoxy(SIZE * 4 + 30, 2);
	cout << "PLAYER 1 : X";
	gotoxy(SIZE * 4 + 30, 4);
	cout << "THANG : ";
	Textcolor(Red);
	gotoxy(SIZE * 4 + 60, 2);
	cout << "PLAYER 2 : O ";
	gotoxy(SIZE * 4 + 60, 4);
	cout << "THANG : ";
	Textcolor(DarkYellow);
	gotoxy(SIZE * 4 + 40, 9);
	cout << "-----------------------";
	gotoxy(SIZE * 4 + 44, 10);
	cout << " W A S D : Move ";
	gotoxy(SIZE * 4 + 44, 11);
	cout << " L : Save Game ";
	gotoxy(SIZE * 4 + 44, 12);
	cout << " ESC : Exit ";

	gotoxy(2, 1);

} 

void Display1()
{
	Textcolor(Blue);
	gotoxy(SIZE * 4 + 30, 2);
	cout << "PLAYER 1 : X";
	gotoxy(SIZE * 4 + 30, 4);
	cout << "THANG : ";
	Textcolor(Red);
	gotoxy(SIZE * 4 + 60, 2);
	cout << "PLAYER 2 (BOT) : O ";
	gotoxy(SIZE * 4 + 60, 4);
	cout << "THANG : ";
	Textcolor(DarkYellow);
	gotoxy(SIZE * 4 + 40, 9);
	cout << "-----------------------";
	gotoxy(SIZE * 4 + 44, 10);
	cout << " W A S D : Move ";
	gotoxy(SIZE * 4 + 44, 11);
	cout << " L : Save Game ";
	gotoxy(SIZE * 4 + 44, 12);
	cout << " ESC : Exit ";

	gotoxy(2, 1);

}

int PlayerVsCom1(Diem& a, int load, char data[30])
{
	int k = 1;
	HienTroChuot();
	_Game g(SIZE, 0, 0);
	g.setCountXY();	
	if (load == -3)
	{
		g.LoadGame(data);
	}
	else
	{
		g.startGame();
		g.setTurn();
	}
	Textcolor(Blue);
	gotoxy(SIZE * 4 + 30 + 10, 4);
	cout << a.score1;
	Textcolor(Red);
	gotoxy(SIZE * 4 + 60 + 10, 4);
	cout << a.score2;
	Display1();
	
	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				g.setX((SIZE * 4 / 2)-2);
				g.setY((SIZE * 2 / 2)-1);
				gotoxy((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
				g.setCommand(13);
			}
			else
			{
				g.TimKiemNuocDi1();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				gotoxy(x, y);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27)
		{
			
			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':
				
				g.moveLeft();
				break;
			case 'D':
				
				g.moveRight();
				break;
			case 'W':
				
				g.moveUp();
				break;
			case 'S':
		
				g.moveDown();
				break;
			case 'L':
				
				g.SaveGame(-3);
				break;
			
			case 13:
				
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()){
					switch (g.KiemTraKetThuc(x, y)){
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom1(a, load, data);
									break;
								
								case 27:
									system("cls");
									MENU(99);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
					
									load = 0;
									return PlayerVsCom1(a, load, data);
									break;								

								case 27:
									system("cls");
									MENU(99);
									break;
								}
							}
						}

						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
		
									load = 0;
									return PlayerVsCom1(a, load, data);
									break;

								case 27:
									system("cls");
									MENU(99);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
}
int PlayerVsCom2(Diem& a, int load, char data[30])
{
	int k = 1;
	HienTroChuot();
	_Game g(SIZE, 0, 0);
	g.setCountXY();
	if (load == -4)
	{
		g.LoadGame(data);
	}
	else
	{
		g.startGame();
		g.setTurn();
	}
	Textcolor(Blue);
	gotoxy(SIZE * 4 + 30 + 10, 4);
	cout << a.score1;
	Textcolor(Red);
	gotoxy(SIZE * 4 + 60 + 10, 4);
	cout << a.score2;
	Display1();	

	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				g.setX((SIZE * 4 / 2) - 2);
				g.setY((SIZE * 2 / 2) - 1);
				gotoxy((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
				g.setCommand(13);
			}
			else
			{
				g.TimKiemNuocDi2();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				gotoxy(x, y);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27){
			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':
				g.moveLeft();
				break;
			case 'D':
				g.moveRight();
				break;
			case 'W':
				g.moveUp();
				break;
			case 'S':
				g.moveDown();
				break;
			case 'L':

				g.SaveGame(-4);
				break;
			case 13:
				
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()){
					switch (g.KiemTraKetThuc(x, y)){
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									load = 0;
									return PlayerVsCom2(a, load, data);
									break;
						
								case 27:
									
									system("cls");
									MENU(99);
									break;
								}
							}
						}

						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':												
									load = 0;
									return PlayerVsCom2(a, load, data);
									break;
								
								case 27:
								
									system("cls");
									MENU(99);
									break;
								}
							}
						}

						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
																
									load = 0;
									return PlayerVsCom2(a, load, data);
									break;
							
								case 27:
									
									system("cls");
									MENU(99);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
}
int PlayerVsCom3(Diem& a, int load, char data[30])
{
	int k = 1;
	HienTroChuot();
	_Game g(SIZE, 0, 0);
	g.setCountXY();
	if (load == -5)
	{
		g.LoadGame(data);
	}
	else
	{
		g.startGame();
		g.setTurn();
	}
	Textcolor(Blue);
	gotoxy(SIZE * 4 + 30 + 10, 4);
	cout << a.score1;
	Textcolor(Red);
	gotoxy(SIZE * 4 + 60 + 10, 4);
	cout << a.score2;
	Display1();

	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				g.setX((SIZE * 4 / 2) - 2);
				g.setY((SIZE * 2 / 2) - 1);
				gotoxy((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
				g.setCommand(13);
			}
			else
			{
				g.TimKiemNuocDi3();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				gotoxy(x, y);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27) {
			
			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':
			
				g.moveLeft();
				break;
			case 'D':
			
				g.moveRight();
				break;
			case 'W':
			
				g.moveUp();
				break;
			case 'S':
			
				g.moveDown();
				break;
			case 'L':

				g.SaveGame(-5);
				break;
			case 13:
				
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()) {
					switch (g.KiemTraKetThuc(x, y)) {
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									
									load = 0;
									return PlayerVsCom3(a, load, data);
									break;
						
								case 27:
								
									system("cls");
									MENU(99);
									break;
								}
							}
						}

						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									
									load = 0;
									return PlayerVsCom3(a, load, data);
									break;
						
								case 27:
								
									system("cls");
									MENU(99);
									break;
								}
							}
						}

						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
								
									load = 0;
									return PlayerVsCom3(a, load, data);
									break;
								
								case 27:
							
									system("cls");
									MENU(99);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
}
int PlayerVsPlayer(Diem& a, int load, char data[30])
{
	int k = 1;
	HienTroChuot();
	_Game g(SIZE, 0, 0);
	g.setCountXY();
	if (load == -30)
	{
		g.setTurn();
		g.LoadGame(data);
	}
	else if (load == -31)
	{
		g.LoadGame(data);
	}
	else
		g.startGame();
	Textcolor(Blue);
	gotoxy(SIZE * 4 + 30 + 10, 4);
	cout << a.score1;
	Textcolor(Red);
	gotoxy(SIZE * 4 + 60 + 10, 4);
	cout << a.score2;
	Display();
	
	while (g.isContinue())
	{
		g.waitKeyBoard();
		if (g.getCommand() == 27){
			//
			return 27;
		}
			
		else
		{
			switch (g.getCommand())
			{
			case 'A':
			
				g.moveLeft();
				break;
			case 'D':
				
				g.moveRight();
				break;
			case 'W':
			
				g.moveUp();
				break;
			case 'S':
			
				g.moveDown();
				break;
			case 'L':
				if (g.getTurn() == 1)
					g.SaveGame(-31);
				else
					g.SaveGame(-30);
				break;
			case 13:
			
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()){
					switch (g.KiemTraKetThuc(x, y)){
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
								
									load = 0;
									return PlayerVsPlayer(a, load, data);
									break;
								
								case 27:
							
									system("cls");
									MENU(99);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
								
									load = 0;
									return PlayerVsPlayer(a, load, data);
									break;
								case 27:
								
									system("cls");
									MENU(99);
									break;
								}
							}
						}
						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
								
									load = 0;
									return PlayerVsPlayer(a, load, data);
									break;
						
								case 27:
								
									system("cls");
									MENU(99);
									break;
								}
							}
						}
						break;

					}
				}
			}
		}
	}
}
