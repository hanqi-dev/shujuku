// 贪吃蛇单元类.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//#include <iostream>
//using namespace std;
//#include "unit.h"
//#include "food.h"
//#include <stdlib.h> 
#include <windows.h> 
#include"windows.h"
#pragma comment(lib,"winmm.lib")
//#include<time.h>
//#include "snake.h"
//#include "control.h"
//#include<conio.h>
#include "controller.h"
int main()
{
	
	//system("color 0F");
	//以下在controller封装实现
	//system("cls");
	//unit a1(10,10,'*');
	//a1.show();
	//food food1;//创建一个食物对象
	//food1.createpos();//随机生成食物
	//food1.show();//显示食物
	//control MyControl;//游戏界面框架
	//MyControl.drawGameArea();
	//MyControl.drawGameInfo();
	//snake snake;//创建蛇
	//nake.showsnake();
	//Sleep(10000);
	//snake.erasesnake();
	//snake.keycontrol(snake,k_right);
	//snake.dir_control(k_right);
	//snake.changeDir();
	//while (true)
	//{
	//	snake.HideCursor();//隐藏光标
	//	snake.move(&food1);//蛇移动加吃食物
	//	snake.finishgame();//碰壁和自残死游戏结束
	//}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//改变边框颜色为红色
	//PlaySound(TEXT("D:\\7895.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//添加背景音乐//绝对路径
	controller c;
	c.playgame();
	return 0;	

}

