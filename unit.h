#pragma once
class unit
{
public:
	int x;
	int y;
	char pic;
	const static int KLEFT = 2;
	const static int KUP = 2;
	const static int KWIDTH = 95;
	const static int KHEIGHT = 25;
public:
	unit(int _x, int _y, char _pic);
	~unit();
	void show();
	void erase();
	static void gotoxy(int a,int b);
};

