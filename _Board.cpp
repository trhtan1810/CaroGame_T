#include "_Board.h"
#include "_Play.h"
#include "_Point.h"

int _Board::getSize(){ return _size; }
int _Board::getLeft(){ return _left; }
int _Board::getTop(){ return _top; }
int _Board::getXAt(int i, int j)
{
	return _pArr[i][j].getX();
}
int _Board::getYAt(int i, int j)
{
	return _pArr[i][j].getY();
}
_Board::_Board()
{
	for (int i = 0; i < _size; i++)
	{
		delete[] _pArr[i];
	}
	delete[] _pArr;
}
_Board::_Board(int pSize, int pX, int pY)
{
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point*[pSize];
	for (int i = 0; i < pSize; i++)
	{
		_pArr[i] = new _Point[pSize];
	}
}
void _Board::loadData(int i, int j, int k)
{
	if (_size == 0) return;
	_pArr[i][j].setX(4 * j + _left + 2);
	_pArr[i][j].setY(2 * i + _top + 1);
	_pArr[i][j].setCheck(k);
	if (k == -1)
	{
		Textcolor(Blue);	//X
		gotoxy(4 * j + _left + 2, 2 * i + _top + 1);
		cout << "X";
		CountX++;
	}
	if (k == 1)
	{
		Textcolor(Red);	//O
		gotoxy(4 * j + _left + 2, 2 * i + _top + 1);
		cout << "O";
		CountY++;
	}

}
void _Board::resetData()
{
	if (_size == 0) return;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			_pArr[i][j].setX(4 * j + _left + 2);
			_pArr[i][j].setY(2 * i + _top + 1);
			_pArr[i][j].setCheck(0);
		}
	}
	
}
void _Board::drawBoard()
{
	gotoxy(0, 0);
	if (_size == 0) return;
	Textcolor(6);
	for (int k = 0; k < 11; k++)
	{

		for (int i = 0; i < 11; i++) // vòng for này dể vẽ hàng có |---|---|
		{

			cout << char(124);
			if (i == 10) // nêu i = 10 thì ra thoart for d? không in thêm các kí t? ---
			{
				break;
			}

			for (int j = 0; j < 3; j++)
			{
				cout << char(45); // kí t? có mã 45 là dâu "-"
			}
			Sleep(1);
		}
		cout << "\n";
		if (k == 10) // n?u k b?ng 10 ta thoát vòng for to dùng d? không in ra thêm các kí t? |  |  |  |
			break;
		for (int j = 0; j <= 40; j = j + 4)
		{
			gotoxy(j, 2 * k + 1);
			cout << char(124);
		}

		cout << k;
		cout << "\n";
	}
	// vẽ số dưới cùng 
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			cout << "  " << 0;
		}
		else if (i > 0 && i <= 9)
		{
			cout << "   " << i;
		}
		else cout << "  " << i;
	}
}
int _Board::checkBoard(int pX, int pY, bool pTurn) // che do choi 0 : Player - 1 :Bot
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn)
				{
					_pArr[i][j].setCheck(-1);
					CountX++;
				}	// X
				else
				{
					_pArr[i][j].setCheck(1);
					CountY++;
				}	// O	
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}

int _Board::KiemTraDong(int x, int y, int value)
{
	int dong, cot;
	//
	int check2dau = 0;
	int countRowLeft = 0, countRowRight = 0;
	cot = (x - _left - 2) / 4;
	dong = (y - _top - 1) / 2;
	int cottrai, cotphai; // Xet dem X ve phia trai, va ve phia phai
	cottrai = cotphai = cot;
	// Xet X chien thang
	// Xet hang ngang
	while (_pArr[dong][cottrai].getCheck() == value)
	{

		countRowLeft++;
		if (cottrai == 0)
			break;
		cottrai--;
	}
	while (_pArr[dong][cotphai].getCheck() == value)
	{

		countRowRight++;
		if (cotphai == _size-1)
			break;
		cotphai++;
	}
	if (_pArr[dong][cottrai].getCheck() == -value && _pArr[dong][cotphai].getCheck() == -value)
		check2dau = 1;
	if ((countRowLeft + countRowRight - 1) == 4 && (check2dau == 0))
	{
		return 1;
	}
	else
		return 0;
	
}

int _Board::KiemTraCot(int x, int y, int value) // Xet chien thang theo hang doc
{
	int dong, cot;
	int check2dau = 0;
	int countColTop = 0, countColBot = 0;
	cot = (x - _left - 2) / 4;
	dong = (y - _top - 1) / 2;
	int dongtren, dongduoi; // Xet bien dem ve phia tren, va ve phia duoi
	dongtren = dongduoi = dong;
	// Xet chien thang
	// Xet hang doc
	while (_pArr[dongtren][cot].getCheck() == value)
	{
		countColTop++;
		
		if (dongtren == 0)
			break;
		dongtren--;
	}
	while (_pArr[dongduoi][cot].getCheck() == value)
	{
		countColBot++;
		
		if (dongduoi == _size - 1)
			break;
		dongduoi++;
	}
	if (_pArr[dongtren][cot].getCheck() == -value && _pArr[dongduoi][cot].getCheck() == -value)
		check2dau = 1;
	if ((countColTop + countColBot - 1) == 4 && (check2dau == 0))
	{
		return 1;
	}
	else
		return 0;
}

int _Board::KiemTraCheo1(int x, int y, int value)
{
	int dong, cot;
	int check2dau = 0;
	int countDiaTop = 0, countDiaBot = 0;
	cot = (x - _left - 2) / 4;
	dong = (y - _top - 1) / 2;
	int dongtren, dongduoi;// Xet dem X ve phia tren, va ve phia duoi
	int cotphai, cottrai;
	dongtren = dongduoi = dong;
	cotphai = cottrai = cot;
	// Xet X chien thang
	// Xet hang ngang
	while (_pArr[dongtren][cotphai].getCheck() == value)
	{
		countDiaTop++;
		
		if (dongtren == 0 || cotphai==_size-1)
			break;
		dongtren--;
		cotphai++;
	}
	while (_pArr[dongduoi][cottrai].getCheck() == value)
	{
		
		countDiaBot++;
		if (dongduoi == _size-1 || cottrai == 0)
			break;
		dongduoi++;
		cottrai--;
	}
	if (_pArr[dongtren][cotphai].getCheck() == -value && _pArr[dongduoi][cottrai].getCheck() == -value)
		check2dau = 1;
	if ((countDiaTop + countDiaBot - 1) == 4 && (check2dau == 0))
	{
		return 1;
	}
	else
		return 0;
	
}
int _Board::KiemTraCheo2(int x, int y, int value)
{
	int dong, cot;
	int check2dau = 0;
	int countDiaTop = 0, countDiaBot = 0;
	cot = (x - _left - 2) / 4;
	dong = (y - _top - 1) / 2;
	int dongtren, dongduoi;// Xet dem X ve phia tren, va ve phia duoi
	int cotphai, cottrai;
	dongtren = dongduoi = dong;
	cotphai = cottrai = cot;
	// Xet X chien thang
	// Xet hang ngang
	while (_pArr[dongtren][cottrai].getCheck() == value)
	{

		countDiaTop++;
		if (dongtren == 0 || cottrai == 0)
			break;
		dongtren--;
		cottrai--;
	}

	while (_pArr[dongduoi][cotphai].getCheck() == value)
	{

		countDiaBot++;
		if (dongduoi == _size - 1 || cotphai == _size - 1)
			break;
		dongduoi++;
		cotphai++;
	}
	if (_pArr[dongtren][cottrai].getCheck() == -value && _pArr[dongduoi][cotphai].getCheck() == -value)
		check2dau = 1;
	if ((countDiaTop + countDiaBot - 1) == 4 && (check2dau == 0))
	{
		return 1;
	}
	else
		return 0;

}
int _Board::testBoard(int x,int y)
{
	// X chien thang
	if (KiemTraDong(x, y, -1) == 1)
		return -1;
	if (KiemTraCot(x, y, -1) == 1)
		return -1;
	if (KiemTraCheo1(x, y, -1) == 1)
		return -1;
	if (KiemTraCheo2(x, y, -1) == 1)
		return -1;
	// O chien thang
	if (KiemTraDong(x, y, 1) == 1)
		return 1;
	if (KiemTraCot(x, y, 1) == 1)
		return 1;
	if (KiemTraCheo1(x, y, 1) == 1)
		return 1;
	if (KiemTraCheo2(x, y, 1) == 1)
		return 1;
	if (CountX + CountY == SIZE*SIZE)
		return 0;
	return 2;
}
_Board::~_Board()
{
}

// Xu li AI
long _Board::SoDiemTanCong_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long DiemHangNgang = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa2 = 0;
	int SoQuanDich2 = 0;
	for (int iDem = 1; iDem < 5 && Cot + iDem < _size; iDem++)
	{
		if (_pArr[Dong][ Cot + iDem].getCheck() == 1)
			SoQuanTa1++;
		if (_pArr[Dong][Cot + iDem].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong][Cot + iDem2].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong][Cot + iDem2].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}


	for (int iDem = 1; iDem < 5 && Cot - iDem >= 0; iDem++)
	{
		if (_pArr[Dong] [Cot - iDem].getCheck() == 1)
			SoQuanTa1++;
		if (_pArr[Dong][Cot - iDem].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong][Cot - iDem2].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong][Cot - iDem2].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (SoQuanDich1 == 2)
		return 0;
	if (SoQuanDich1 == 0)
		DiemHangNgang += Attack_Score[SoQuanTa1] * 2;
	else
		DiemHangNgang += Attack_Score[SoQuanTa1];
	if (SoQuanDich2 == 0)
		DiemHangNgang += Attack_Score[SoQuanTa2] * 2;
	else
		DiemHangNgang += Attack_Score[SoQuanTa2];

	if (SoQuanTa1 >= SoQuanTa2)
		DiemHangNgang -= 1;
	else
		DiemHangNgang -= 2;
	if (SoQuanTa1 == 3)
		DiemHangNgang *= 2;
	if (SoQuanTa1 == 0)
		DiemHangNgang -= Defend_Score[SoQuanDich1] * 2;
	else
		DiemHangNgang -= Defend_Score[SoQuanDich1];
	if (SoQuanTa2 == 0)
		DiemHangNgang -= Defend_Score[SoQuanDich2] * 2;
	else
		DiemHangNgang -= Defend_Score[SoQuanDich2];
	return DiemHangNgang;
}
long _Board::SoDiemTanCong_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long DiemHangDoc = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa2 = 0;
	int SoQuanDich2 = 0;
	for (int iDem = 1; iDem < 5 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot].getCheck() == 1)
			SoQuanTa1++;
		if (_pArr[Dong + iDem][Cot].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong + iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}
			
	}
	
	for (int iDem = 1; iDem < 5 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot].getCheck() == 1)
			SoQuanTa1++;
		if (_pArr[Dong - iDem][Cot].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong - iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}

	if (SoQuanDich1 == 2)
		return 0;
	if (SoQuanDich1 == 0)
		DiemHangDoc += Attack_Score[SoQuanTa1] * 2;
	else
		DiemHangDoc += Attack_Score[SoQuanTa1];
	if (SoQuanDich2 == 0)
		DiemHangDoc += Attack_Score[SoQuanTa2] * 2;
	else
		DiemHangDoc += Attack_Score[SoQuanTa2];

	if (SoQuanTa1 >= SoQuanTa2)
		DiemHangDoc -= 1;
	else
		DiemHangDoc -= 2;
	if (SoQuanTa1 == 3)
		DiemHangDoc *= 2;
	if (SoQuanTa1 == 0)
		DiemHangDoc -= Defend_Score[SoQuanDich1] * 2;
	else
		DiemHangDoc -= Defend_Score[SoQuanDich1];
	if (SoQuanTa2 == 0)
		DiemHangDoc -= Defend_Score[SoQuanDich2] * 2;
	else
		DiemHangDoc -= Defend_Score[SoQuanDich2];
	return DiemHangDoc;
}

long _Board::SoDiemTanCong_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long DiemCheoNguoc = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa2 = 0;
	int SoQuanDich2 = 0;
	for (int iDem = 1; iDem < 5 && Cot + iDem < _size && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][ Cot + iDem].getCheck() == 1)
			SoQuanTa1++;
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot + iDem2 < _size && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 5 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem] [Cot - iDem].getCheck() == 1)
			SoQuanTa1++;
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (SoQuanDich1 == 2)
		return 0;
	if (SoQuanDich1 == 0)
		DiemCheoNguoc += Attack_Score[SoQuanTa1] * 2;
	else
		DiemCheoNguoc += Attack_Score[SoQuanTa1];
	if (SoQuanDich2 == 0)
		DiemCheoNguoc += Attack_Score[SoQuanTa2] * 2;
	else
		DiemCheoNguoc += Attack_Score[SoQuanTa2];

	if (SoQuanTa1 >= SoQuanTa2)
		DiemCheoNguoc -= 1;
	else
		DiemCheoNguoc -= 2;
	if (SoQuanTa1 == 3)
		DiemCheoNguoc *= 2;
	if (SoQuanTa1 == 0)
		DiemCheoNguoc -= Defend_Score[SoQuanDich1] * 2;
	else
		DiemCheoNguoc -= Defend_Score[SoQuanDich1];
	if (SoQuanTa2 == 0)
		DiemCheoNguoc -= Defend_Score[SoQuanDich2] * 2;
	else
		DiemCheoNguoc -= Defend_Score[SoQuanDich2];
	return DiemCheoNguoc;
}
long _Board::SoDiemTanCong_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long DiemCheoXuoi = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa2 = 0;
	int SoQuanDich2 = 0;
	for (int iDem = 1; iDem < 5 && Cot - iDem >= 0 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem] [Cot - iDem].getCheck() == 1)
			SoQuanTa1++;
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot - iDem2 >= 0 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 5 && Cot + iDem < _size && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem] [Cot + iDem].getCheck()== 1)
			SoQuanTa1++;
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == -1)
		{
			SoQuanDich1++;
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot + iDem2 < _size && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 1)
					SoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == -1)
				{
					SoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (SoQuanDich1 == 2)
		return 0;
	if (SoQuanDich1 == 0)
		DiemCheoXuoi += Attack_Score[SoQuanTa1] * 2;
	else
		DiemCheoXuoi += Attack_Score[SoQuanTa1];
	if (SoQuanDich2 == 0)
		DiemCheoXuoi += Attack_Score[SoQuanTa2] * 2;
	else
		DiemCheoXuoi += Attack_Score[SoQuanTa2];

	if (SoQuanTa1 >= SoQuanTa2)
		DiemCheoXuoi -= 1;
	else
		DiemCheoXuoi -= 2;
	if (SoQuanTa1 == 3)
		DiemCheoXuoi *= 2;
	if (SoQuanTa1 == 0)
		DiemCheoXuoi -= Defend_Score[SoQuanDich1] * 2;
	else
		DiemCheoXuoi -= Defend_Score[SoQuanDich1];
	if (SoQuanTa2 == 0)
		DiemCheoXuoi -= Defend_Score[SoQuanDich2] * 2;
	else
		DiemCheoXuoi -= Defend_Score[SoQuanDich2];
	return DiemCheoXuoi;
}

long _Board::SoDiemPhongThu_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long DiemHangDoc = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich2 = 0;
	int SoQuanTa2 = 0;
	for (int iDem = 1; iDem < 5 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][ Cot].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}
		if (_pArr[Dong + iDem][Cot].getCheck() == -1)
			SoQuanDich1++;
		if (_pArr[Dong + iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot].getCheck() == -1)
					SoQuanDich2++;
				if (_pArr[Dong + iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 5 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}
		if (_pArr[Dong - iDem][Cot].getCheck() == -1)
			SoQuanDich1++;
		if (_pArr[Dong - iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot].getCheck() == -1)
					SoQuanDich2++;
				if (_pArr[Dong - iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}
	}
	

	if (SoQuanTa1 == 2)
		return 0;
	if (SoQuanTa1 == 0)
		DiemHangDoc += Defend_Score[SoQuanDich1] * 2;
	else
		DiemHangDoc += Defend_Score[SoQuanDich1];

	if (SoQuanDich1 >= SoQuanDich2)
		DiemHangDoc -= 1;
	else
		DiemHangDoc -= 2;
	if (SoQuanDich1 == 3)
		DiemHangDoc *= 2;
	return DiemHangDoc;
}

long _Board::SoDiemPhongThu_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long DiemHangNgang = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich2 = 0;
	int SoQuanTa2 = 0;
	for (int iDem = 1; iDem < 5 && Cot + iDem < _size; iDem++)
	{
		if (_pArr[Dong][ Cot + iDem].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}
		if (_pArr[Dong][Cot + iDem].getCheck() == -1)
			SoQuanDich1++;
		if (_pArr[Dong][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong][Cot + iDem2].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}
				if (_pArr[Dong][Cot + iDem2].getCheck() == -1)
					SoQuanDich2++;
				if (_pArr[Dong][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int iDem = 1; iDem < 5 && Cot - iDem >= 0; iDem++)
	{
		if (_pArr[Dong][ Cot - iDem].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong][Cot - iDem2].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}
				if (_pArr[Dong][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong][Cot - iDem2].getCheck() == -1)
					SoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == -1)
			SoQuanDich1++;
	}

	if (SoQuanTa1 == 2)
		return 0;
	if (SoQuanTa1 == 0)
		DiemHangNgang += Defend_Score[SoQuanDich1] * 2;
	else
		DiemHangNgang += Defend_Score[SoQuanDich1];

	if (SoQuanDich1 >= SoQuanDich2)
		DiemHangNgang -= 1;
	else
		DiemHangNgang -= 2;
	if (SoQuanDich1 == 3)
		DiemHangNgang *= 2;
	return DiemHangNgang;
}

long _Board::SoDiemPhongThu_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{

	long DiemCheoNguoc = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich2 = 0;
	int SoQuanTa2 = 0;
	for (int iDem = 1; iDem < 5 && Cot + iDem < _size && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][ Cot + iDem].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot + iDem2 < _size && Dong + iDem2< _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == -1)
					SoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == -1)
			SoQuanDich1++;
	}

	for (int iDem = 1; iDem < 5 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem] [Cot - iDem].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}

		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}

				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == -1)
					SoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == -1)
			SoQuanDich1++;
	}
	if (SoQuanTa1 == 2)
		return 0;
	if (SoQuanTa1 == 0)
		DiemCheoNguoc += Defend_Score[SoQuanDich1] * 2;
	else
		DiemCheoNguoc += Defend_Score[SoQuanDich1];

	if (SoQuanDich1 >= SoQuanDich2)
		DiemCheoNguoc -= 1;
	else
		DiemCheoNguoc -= 2;
	if (SoQuanDich1 == 3)
		DiemCheoNguoc *= 2;
	return DiemCheoNguoc;
}

long _Board::SoDiemPhongThu_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long DiemCheoXuoi = 0;
	int SoQuanDich1 = 0;
	int SoQuanTa1 = 0;
	int SoQuanDich2 = 0;
	int SoQuanTa2 = 0;
	for (int iDem = 1; iDem < 5 && Cot - iDem >= 0 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem] [Cot - iDem].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 6 && Cot - iDem2 >= 0 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == -1)
					SoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == -1)
			SoQuanDich1++;
	}

	for (int iDem = 1; iDem < 5 && Cot + iDem < _size && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][ Cot + iDem].getCheck() == 1)
		{
			SoQuanTa1++;
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem < 6 && Cot + iDem2 < _size && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 1)
				{
					SoQuanTa2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == -1)
					SoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == -1)
			SoQuanDich1++;
	}


	if (SoQuanTa1 == 2)
		return 0;
	if (SoQuanTa1 == 0)
		DiemCheoXuoi += Defend_Score[SoQuanDich1] * 2;
	else
		DiemCheoXuoi += Defend_Score[SoQuanDich1];

	if (SoQuanDich1 >= SoQuanDich2)
		DiemCheoXuoi -= 1;
	else
		DiemCheoXuoi -= 2;
	if (SoQuanDich1 == 3)
		DiemCheoXuoi *= 2;
	return DiemCheoXuoi;
}
_Point _Board::Tim_Kiem_NuocDi_1()
{
	_Point Oco ;
	int dong=0, cot=0;
	long Diem = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1,Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
	Oco.setX(cot*4+2);
	Oco.setY(dong*2+1);
	return Oco;
}
_Point _Board::Tim_Kiem_NuocDi_2()
{
	_Point Oco;
	int dong = 0, cot = 0;
	long Diem = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
	Oco.setX(cot * 4 + 2);
	Oco.setY(dong * 2 + 1);
	return Oco;
}
_Point _Board::Tim_Kiem_NuocDi_3()
{
	_Point Oco;
	int dong = 0, cot = 0;
	long Diem = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score3, Attack_Score3);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score3, Attack_Score3);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score3, Attack_Score3);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score3, Attack_Score3);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score3, Attack_Score3);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score3, Attack_Score3);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score3, Attack_Score3);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score3, Attack_Score3);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
	Oco.setX(cot * 4 + 2);
	Oco.setY(dong * 2 + 1);
	return Oco;
}