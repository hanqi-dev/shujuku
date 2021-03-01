#include "snake.h"
//#include "food.h"
//#include "unit.h"
#include<iostream>
#include <stdlib.h>
#include<windows.h>
#include<conio.h>//vector
using namespace std;
snake::snake(int x, int y, int len, int speed, Dir dir,char pic)
{
	m_HeadX = x;
	m_HeadY = y;
	m_Len = len;
	m_Speed = speed;
	m_Dir = dir;
	m_pic = pic;
	score = 0;
	for (int i = 0; i < m_Len; i++)//蛇身初始化
	{
		unit unit(0, 0, pic);
		m_body.push_back(unit);
		switch (dir)
		{
		case k_up:
			m_body[i].x = m_HeadX;
			m_body[i].y = m_HeadY - i;
			break;
		case k_down:
			m_body[i].x = m_HeadX;
			m_body[i].y = m_HeadY + i;
			break;
		case k_left:
			m_body[i].x = m_HeadX + i;
			m_body[i].y = m_HeadY;
			break;
		case k_right:
			m_body[i].x = m_HeadX - i;
			m_body[i].y = m_HeadY;
			break;
		default:
			//system("pause>null");
			break;
		}
	}
}
snake::~snake()
{

}
void snake::showsnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_body[i].show();
	}
}
void snake::erasesnake()
{
	for (int i = 0; i < m_Len; i++)
	{
		m_body[i].erase();
	}
}
void snake::move(food *f)//移动函数//创建一个指针f来传递food实例
{
		for(int i = m_Len-1; i>0;i--)//后面的坐标等于前面的坐标
		{
				m_body[i].x = m_body[i - 1].x;
				m_body[i].y = m_body[i - 1].y;
		}
		m_Dir=changeDir() ;
	switch(m_Dir)//判断方向对头做出相应的操作
	{
		case k_up:
		{
			m_body[0].y--;
			break;
		}
		case k_down:
		{
			m_body[0].y++;
			break;
		}
			
		case k_left:
		{
			m_body[0].x--;
			break;
		}
			
		case k_right:
		{
			m_body[0].x++;
			break;
		}
		default:
			break;

	}
	eatfood(f);//吃食物
	showsnake();//显示蛇/.21																																																					不
	Sleep(m_Speed);//睡5s
	erasesnake();//擦除蛇
}
int snake::changeDir()//改变方向，利用返回值传递
{
	if (_kbhit())
	{
		int keyvalue = _getch();
			switch (keyvalue)//判断按键是什么
			{
			case 72:
			case 'w':
			case 'W':
				if (m_Dir == k_left || m_Dir == k_right)
				{
					m_Dir = k_up;
				}
				break;
			case 80:
			case 's':
			case 'S':
				if (m_Dir == k_left || m_Dir == k_right)
				{
					m_Dir = k_down;
				}
				break;
			case 75:
			case 'A':
			case 'a':
				if (m_Dir == k_up || m_Dir == k_down)
				{
					m_Dir = k_left;
				}
				break;
			case 77:
			case 'D':
			case 'd':
				if (m_Dir == k_up || m_Dir == k_down)
				{
					m_Dir = k_right;
				}
				break;
			default:
				//system("pause>null");
				break;
			
			}
			//暂停操作：如果不是这几个键，那么system(pause>null);
			/*if (keyvalue != 72 || keyvalue != 80 || keyvalue != 75 || keyvalue != 77)
			{
				system("pause > null");
			}*/
	}
	return m_Dir;
}
//void snake::keycontrol(snake &_snk,int _key)
//{ 
//			switch (_key)
//			{
//			case ' ':
//			{
//				_snk.dir_control('s');
//				break;
//			}
//				
//			case 'w':
//			case 'W':
//			case 72:
//			{
//				_snk.dir_control('u');
//				break;
//			}
//			case 'a':
//			case 'A':
//			case 75:
//			{
//				_snk.dir_control('l');
//				break;
//			}
//			case 's':
//			case 'S':
//			case 80:
//			{
//				_snk.dir_control('d');
//				break;
//			}
//			case 'd':
//			case 'D':
//			case 77:
//			{
//				_snk.dir_control('r');
//				break;
//			}
//			default:
//			{  
//				break;
//			}
//			if (_kbhit())
//			{
//				_key = _getch();
//			}
//			}
//}
//void snake::dir_control(char _dir)
//{
//	switch (_dir)
//	{
//	case's':
//		this->m_Dir = k_stop;
//	case'l':
//		if(this->m_Dir!=k_right)
//		this->m_Dir = k_left;
//	case'r':
//		if (this->m_Dir != k_left)
//			this->m_Dir = k_right;
//	case'u':
//		if (this->m_Dir != k_down)
//			this->m_Dir = k_up;
//	case'd':
//		if (this->m_Dir != k_up)
//			this->m_Dir = k_down;
//	default:
//		break;
//	}
//}
//吃食物
bool snake::eatfood(food *food1)//吃食物
{
	if (m_body[0].x == food1->x && m_body[0].y == food1->y)//蛇头与食物坐标重合
	{
		unit unit(0, 0, m_pic);//将新节点添加到蛇身
		m_body.push_back(unit);
		m_Len++;
		score+=50;//每吃一个分数加50
		unit::gotoxy(51,3);//定位坐标
		cout << score;
		unit::gotoxy(66,3);
		checkpoint = checkpointincreace();//收到关卡的改变值
		cout << checkpoint;
		//m_Speed += 50;//速度每吃一个降低50
		if (m_Speed < 0)m_Speed = 0;
		for (int i = 0; i < m_Len; i++)//优化//判断食物是否出现在蛇身上
		{
			if (m_body[i].x == food1->x&&m_body[i].y == food1->y)//食物的坐标与蛇的坐标重合
			{
				food1->createpos();
				food1->show();
			}
		}
		//food1->createpos();//随机生成food
		//food1->show();	//显示food
	}
	else
		return false;
}
int snake::checkpointincreace()//关卡增加
{
	checkpoint = 1;
	if (score % 300 == 0)
	{
		checkpoint += 1;
		m_Speed += 50;//速度每吃一个降低50
	}
	return checkpoint;
}
//撞墙和自残死亡游戏结束
void snake::finishgame()
{
	if (m_body[0].x >= unit::KWIDTH || m_body[0].x <= unit::KLEFT || m_body[0].y >= unit::KHEIGHT+2 || m_body[0].y <= unit::KUP+3)//碰壁死
	{
		//弹出一个界面游戏结束
		cout << system("cls");//清屏
		int ret = MessageBox(NULL, L"游戏结束", L"是否要重新开始", MB_YESNO);
		//MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_YESNO);
		if (ret == IDYES)
		{
			cout << "请×掉控制台重新开始！"<<endl;
		}
		else
		{
			MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_OK);
		}
		cin.get();
	}
	for (int i = 1; i < m_Len; i++)//自残死
	{
		if (m_body[0].x == m_body[i].x&&m_body[0].y == m_body[i].y)
		{
			//弹出一个界面游戏结束
			//MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_YESNO);
			cout << system("cls");
			const static int ret = MessageBox(NULL, L"游戏结束", L"是否要重新开始", MB_YESNO);
		//MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_YESNO);
		if (ret == IDYES)
		{
			cout << "请×掉控制台重新开始！"<<endl;
		}
		else
		{
			MessageBox(NULL, L"游戏结束", L"游戏结束！", MB_OK);
		}
		cin.get();
		}
	}
}
void snake::HideCursor()			//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}