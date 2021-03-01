#pragma once
#include <vector>
using namespace std;
#include "unit.h"
#include"food.h"
#include<Windows.h>
 enum Dir
{
	k_stop,k_left, k_right, k_up, k_down
};
class snake
{
public:
	int m_HeadX;
	int m_HeadY;
	int m_Len;
	int m_Speed;
	int m_pic;
	int m_Dir;
	int score;//·ÖÊý
	int checkpoint;//¹Ø¿¨
	vector<unit> m_body;
public:
	snake(int x=45,int y=20,int len=5,int speed=200,Dir dir=k_right, char pic = '*');
	~snake();
	void showsnake();
	void erasesnake();
	void move(food *f);
	int changeDir();
	bool eatfood(food *food1);
	void finishgame();
	void HideCursor();
	int checkpointincreace();
};


