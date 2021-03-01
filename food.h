#pragma once
#include"unit.h"
#include<vector>
#include<stdlib.h>
class food :public unit
{
public:
	food(int _x=10,int _y=10,char _pic='*');
	~food();
	void createpos();
};

