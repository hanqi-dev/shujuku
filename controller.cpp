#include "controller.h"
#include"snake.h"
#include"food.h"
#include "control.h"
#include<conio.h>
#include<Windows.h>
#include"windows.h"
#pragma comment(lib,"winmm.lib")
void controller::playgame()
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//改变边框颜色为红色
	PlaySound(TEXT("D:\\7895.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//添加背景音乐//绝对路径
	food *food1=new food();
	snake *snake1=new snake();
	food1->createpos();
	food1->show();
	control MyControl;//游戏界面框架
	MyControl.drawGameArea();
	MyControl.drawGameInfo();
	while (true)
	{
		snake1->HideCursor();//隐藏光标
		snake1->move(food1);//蛇移动加吃食物
		snake1->finishgame();//碰壁和自残死游戏结束
	}
	delete food1;
	delete snake1;
}
controller::~controller() 
{

}
