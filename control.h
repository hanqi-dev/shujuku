#pragma once
#include <Windows.h>
class control
{
public:
	COORD m_coor;
public:
	control();
	~control();
	void drawGameArea();
	void drawGameInfo();
};

