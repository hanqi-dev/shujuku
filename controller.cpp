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
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//�ı�߿���ɫΪ��ɫ
	PlaySound(TEXT("D:\\7895.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);//��ӱ�������//����·��
	food *food1=new food();
	snake *snake1=new snake();
	food1->createpos();
	food1->show();
	control MyControl;//��Ϸ������
	MyControl.drawGameArea();
	MyControl.drawGameInfo();
	while (true)
	{
		snake1->HideCursor();//���ع��
		snake1->move(food1);//���ƶ��ӳ�ʳ��
		snake1->finishgame();//���ں��Բ�����Ϸ����
	}
	delete food1;
	delete snake1;
}
controller::~controller() 
{

}
