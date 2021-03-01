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
void unit::gotoxy(int x, int y)//坐标定位
{
	HANDLE hout;
	COORD coord;// 光标位置
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);// 输出句柄
	SetConsoleCursorPosition(hout, coord);// 设置光标位置 
}
/*void unit::gotoxy()
{
	srand(time(0));    // 更新随机数种子
	COORD  pt;         // 光标位置
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 输出句柄
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;          // 窗口缓冲区信息结构体
	GetConsoleScreenBufferInfo(hOut, &screenInfo);  // 获取窗口信息
	pt.X = rand() % 50;            // 不能超过窗口缓冲区尺寸，
	pt.Y = rand() % 50;            // 或者自己控制范围
	SetConsoleCursorPosition(hOut, pt);	            // 设置光标位置 
}*/
void unit::show()//显示函数
{
	gotoxy(x,y);
	cout << pic;
}
void unit::erase()//擦除函数
{
	gotoxy(x,y);
	cout << " ";
}