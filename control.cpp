#include <iostream>
using namespace std;
#include "food.h"
#include "control.h"
#include "unit.h"
#include "snake.h"

control::control()
{
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	//m_coor = GetLargestConsoleWindowSize(hOut);
	//CloseHandle(hOut); // �رձ�׼����豸���
	///*const int KWIDTH = coor.X;
	//const int KHEIGHT = coor.Y;*/
	///*m_coor = coor;*/
	/*RECT rect;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetClientRect(hOut, &rect);	*/
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* ��ȡ��׼������ */
	GetConsoleScreenBufferInfo(hOut, &scr);
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;

}


control::~control()
{
}

void control::drawGameArea()
{
	//todo
	/*for (int i = unit::KLEFT; i <=  m_coor.X - 2*unit::KLEFT; i++)
	{
		unit::gotoxy(i, unit::KUP);
		cout << "-";
		unit::gotoxy(i, unit::KUP+2);
		cout << "-";
		unit::gotoxy(i, m_coor.Y - 2*unit::KUP);
		cout << "-";
	}

	for (int i = unit::KUP+1; i <= m_coor.Y -1- 2 * unit::KUP; i++)
	{
		unit::gotoxy(unit::KLEFT, i);
		cout << "|";
		unit::gotoxy(m_coor.X - 2 * unit::KLEFT, i);
		cout << "|";
	}*/
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int j = 0; j < unit::KWIDTH; j++)
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//�ı�߿���ɫΪ��ɫ
		cout << "-";
	}

	for (int i = 0; i < unit::KHEIGHT; i++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + i);//(2,23)
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + i);//(71,23)
		cout << "|";
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);//(2,23)
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);//(3,4)
	for (int i = 0; i < unit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void control::drawGameInfo()//���
{
	//todo
	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);

	cout << "��Ϸ���ƣ�̰����";

	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);

	cout << "��д�ߣ�dada";

	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);//(42,3)/

	cout << "��ǰ�÷�";

	//unit::gotoxy(unit::KLEFT + unit::KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);//(57,3)

	cout << "��ǰ�ؿ�";

	//unit::gotoxy(unit::KLEFT + unit::KLEVEL_OFFSET, KUP + 1);

	//cout << m_iLevel;

}