#pragma once
#include "_Point.h"
#include "_Common.h"
#include "_Board.h"
#include "_Game.h"

#define SIZE			10  // SIZE BÀN CỜ 
#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed			4
#define DarkPink		5
#define DarkYellow		6
#define DarkWhite		7
#define Grey			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red				12
#define Pink			13
#define Yellow			14
#define White			15
#define defaultColor		7 
// MẶC ĐỊNH CÁC MÀU CƠ BẢN
struct Diem
{
	int score1;
	int score2;
};
// Tỉ số thắng thua 

void Textcolor(int n); // Đổi màu kí tự 
void AnTroChuot();    // Ẩn trỏ chuột
void HienTroChuot();  // Hiện trỏ chuột
void MENU(int); // Menu Chính
int PlayerVsCom1(Diem& a, int, char data[30]); // BOT EASY
int PlayerVsCom2(Diem& a, int, char data[30]); // BOT NORMAL
int PlayerVsCom3(Diem& a, int, char data[30]); // BOT HARD
int PlayerVsPlayer(Diem& a, int, char data[30]); // P VS P
void Help(); // Help
void About(); // About 
void LoadLoad(); // Load Game