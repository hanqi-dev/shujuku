#include "food.h"
#include "unit.h"
#include <iostream>
using namespace std;
#include <stdlib.h> 
#include <windows.h> 
#include<time.h>
//food::food(unit &p)
//{
//		x = p.x; 】

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
void food::createpos()//食物随机出现
{
	srand((int)time(NULL));    // 更新随机数种子
	//COORD  pt;         // 光标位置
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 输出句柄
	//CONSOLE_SCREEN_BUFFER_INFO screenInfo;          // 窗口缓冲区信息结构体
	//GetConsoleScreenBufferInfo(hOut, &screenInfo);  // 获取窗口信息
	//pt.x = rand() % screeninfo.dwsize.x;            // 不能超过窗口缓冲区尺寸，
	//pt.y = rand() % screeninfo.dwsize.y;            // 或者自己控制范围
	x= KLEFT + 1 + rand() % (KWIDTH - 2);//food横坐标随机改变
	y= KUP + 3 + rand() % (KHEIGHT - 2);//food纵坐标随机改变
	/*gotoxy(pt.X, pt.Y);
	cout << pic;*/
	//SetConsoleCursorPosition(hOut, pt);
}
