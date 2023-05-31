#pragma once
#include "includes.h"
class House
{
private:
	int numHouse;
	int amountHuman;
	Human** h;
public:
	House(int nHouse) : House(nHouse, 0) {};
	House(int nHouse, int amHuman);
	House(int nHouse, int amHuman,const Human* h);
	
	House(const House& obj);
	
	void displayHouse();
	void changeNumber(int num);
	void delHuman(int index);
	void addHuman(const Human hum);
	void addHuman();

	~House();
};


