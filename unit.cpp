#include <iostream>
using namespace std;
#include <stdlib.h> 
#include <windows.h> 
#include "unit.h"
#include<time.h>
unit::unit(int _x,int _y,char _pic):x(_x),y(_y),pic(_pic)
{

}
unit::~unit()
{

}
void unit::gotoxy(int x, int y)//���궨λ
{
	HANDLE hout;
	COORD coord;// ���λ��
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);// ������
	SetConsoleCursorPosition(hout, coord);// ���ù��λ�� 
}
/*void unit::gotoxy()
{
	srand(time(0));    // �������������
	COORD  pt;         // ���λ��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // ������
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;          // ���ڻ�������Ϣ�ṹ��
	GetConsoleScreenBufferInfo(hOut, &screenInfo);  // ��ȡ������Ϣ
	pt.X = rand() % 50;            // ���ܳ������ڻ������ߴ磬
	pt.Y = rand() % 50;            // �����Լ����Ʒ�Χ
	SetConsoleCursorPosition(hOut, pt);	            // ���ù��λ�� 
}*/
void unit::show()//��ʾ����
{
	gotoxy(x,y);
	cout << pic;
}
void unit::erase()//��������
{
	gotoxy(x,y);
	cout << " ";
}