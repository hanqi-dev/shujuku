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
	for (int i = 0; i < m_Len; i++)//�����ʼ��
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
void snake::move(food *f)//�ƶ�����//����һ��ָ��f������foodʵ��
{
		for(int i = m_Len-1; i>0;i--)//������������ǰ�������
		{
				m_body[i].x = m_body[i - 1].x;
				m_body[i].y = m_body[i - 1].y;
		}
		m_Dir=changeDir() ;
	switch(m_Dir)//�жϷ����ͷ������Ӧ�Ĳ���
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
	eatfood(f);//��ʳ��
	showsnake();//��ʾ��/.21																																																					��
	Sleep(m_Speed);//˯5s
	erasesnake();//������
}
int snake::changeDir()//�ı䷽�����÷���ֵ����
{
	if (_kbhit())
	{
		int keyvalue = _getch();
			switch (keyvalue)//�жϰ�����ʲô
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
			//��ͣ��������������⼸��������ôsystem(pause>null);
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
//��ʳ��
bool snake::eatfood(food *food1)//��ʳ��
{
	if (m_body[0].x == food1->x && m_body[0].y == food1->y)//��ͷ��ʳ�������غ�
	{
		unit unit(0, 0, m_pic);//���½ڵ���ӵ�����
		m_body.push_back(unit);
		m_Len++;
		score+=50;//ÿ��һ��������50
		unit::gotoxy(51,3);//��λ����
		cout << score;
		unit::gotoxy(66,3);
		checkpoint = checkpointincreace();//�յ��ؿ��ĸı�ֵ
		cout << checkpoint;
		//m_Speed += 50;//�ٶ�ÿ��һ������50
		if (m_Speed < 0)m_Speed = 0;
		for (int i = 0; i < m_Len; i++)//�Ż�//�ж�ʳ���Ƿ������������
		{
			if (m_body[i].x == food1->x&&m_body[i].y == food1->y)//ʳ����������ߵ������غ�
			{
				food1->createpos();
				food1->show();
			}
		}
		//food1->createpos();//�������food
		//food1->show();	//��ʾfood
	}
	else
		return false;
}
int snake::checkpointincreace()//�ؿ�����
{
	checkpoint = 1;
	if (score % 300 == 0)
	{
		checkpoint += 1;
		m_Speed += 50;//�ٶ�ÿ��һ������50
	}
	return checkpoint;
}
//ײǽ���Բ�������Ϸ����
void snake::finishgame()
{
	if (m_body[0].x >= unit::KWIDTH || m_body[0].x <= unit::KLEFT || m_body[0].y >= unit::KHEIGHT+2 || m_body[0].y <= unit::KUP+3)//������
	{
		//����һ��������Ϸ����
		cout << system("cls");//����
		int ret = MessageBox(NULL, L"��Ϸ����", L"�Ƿ�Ҫ���¿�ʼ", MB_YESNO);
		//MessageBox(NULL, L"��Ϸ����", L"��Ϸ������", MB_YESNO);
		if (ret == IDYES)
		{
			cout << "���������̨���¿�ʼ��"<<endl;
		}
		else
		{
			MessageBox(NULL, L"��Ϸ����", L"��Ϸ������", MB_OK);
		}
		cin.get();
	}
	for (int i = 1; i < m_Len; i++)//�Բ���
	{
		if (m_body[0].x == m_body[i].x&&m_body[0].y == m_body[i].y)
		{
			//����һ��������Ϸ����
			//MessageBox(NULL, L"��Ϸ����", L"��Ϸ������", MB_YESNO);
			cout << system("cls");
			const static int ret = MessageBox(NULL, L"��Ϸ����", L"�Ƿ�Ҫ���¿�ʼ", MB_YESNO);
		//MessageBox(NULL, L"��Ϸ����", L"��Ϸ������", MB_YESNO);
		if (ret == IDYES)
		{
			cout << "���������̨���¿�ʼ��"<<endl;
		}
		else
		{
			MessageBox(NULL, L"��Ϸ����", L"��Ϸ������", MB_OK);
		}
		cin.get();
		}
	}
}
void snake::HideCursor()			//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}