#include "food.h"
#include "unit.h"
#include <iostream>
using namespace std;
#include <stdlib.h> 
#include <windows.h> 
#include<time.h>
//food::food(unit &p)
//{
//		x = p.x; ��

//		y = p.y; 
//		pic = p.pic;
//}
food::food(int _x, int _y, char _pic):unit(x,y,pic)
{
	x = _x;
	y = _y;
	pic = _pic;
}
food::~food()
{

}
void food::createpos()//ʳ���������
{
	srand((int)time(NULL));    // �������������
	//COORD  pt;         // ���λ��
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // ������
	//CONSOLE_SCREEN_BUFFER_INFO screenInfo;          // ���ڻ�������Ϣ�ṹ��
	//GetConsoleScreenBufferInfo(hOut, &screenInfo);  // ��ȡ������Ϣ
	//pt.x = rand() % screeninfo.dwsize.x;            // ���ܳ������ڻ������ߴ磬
	//pt.y = rand() % screeninfo.dwsize.y;            // �����Լ����Ʒ�Χ
	x= KLEFT + 1 + rand() % (KWIDTH - 2);//food����������ı�
	y= KUP + 3 + rand() % (KHEIGHT - 2);//food����������ı�
	/*gotoxy(pt.X, pt.Y);
	cout << pic;*/
	//SetConsoleCursorPosition(hOut, pt);
}
