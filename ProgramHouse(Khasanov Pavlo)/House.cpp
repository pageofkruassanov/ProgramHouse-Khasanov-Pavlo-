#include "includes.h"

House::House(int nHouse, int amHuman)
{
	if (nHouse >= 0)
		numHouse = nHouse;
	else
		numHouse = -1;

	if (amHuman > 0) {
		amountHuman = amHuman;

		this->h = new Human * [amHuman];

		for (int i = 0; i < amHuman; i++) {
			this->h[i] = new Human();
		}
	}
	else {
		amountHuman = 0;

		this->h = nullptr;
	}
}

House::House(int nHouse, int amHuman, const Human* h)
{
	if (nHouse >= 0)
		numHouse = nHouse;
	else
		numHouse = -1;

	if (amHuman > 0) {
		amountHuman = amHuman;

		this->h = new Human * [amHuman];

		for (int i = 0; i < amHuman; i++) {
			this->h[i] = new Human(h[i]);
		}
	}
	else {
		amountHuman = 0;

		this->h = nullptr;
	}
}

House::House(const House& obj)
{
	if (obj.amountHuman == 0) {
		this->amountHuman = 0;
		this->numHouse = obj.numHouse;
		this->h = nullptr;
	}
	else {
		this->amountHuman = obj.amountHuman;
		this->numHouse = obj.numHouse;
		this->h = new Human * [amountHuman];
		for (int i = 0; i < amountHuman; i++) {
			this->h[i] = new Human(*obj.h[i]);
		}
	}
}

void House::displayHouse()
{
	if (h == nullptr || amountHuman == 0)
		return;

	cout << "Number house: " << numHouse << endl;
	cout << "Amount human: " << amountHuman << endl << endl;
	cout << "****Humans****" << endl << endl;
	for (int i = 0; i < amountHuman; i++) {
		h[i]->displayHuman();
	}
}

void House::changeNumber(int num)
{
	if (num < 0)
		return;
	numHouse = num;
}

void House::delHuman(int index)
{
	if (index < 0 || index >= amountHuman || amountHuman == 0 || h == nullptr)
		return;

	Human** tempH = new Human * [amountHuman - 1];
	for (int i = 0; i < amountHuman - 1; i++) {
		if (i < index)
			tempH[i] = new Human(*h[i]);
		else
			tempH[i] = new Human(*h[i + 1]);
	}

	for (int i = 0; i < amountHuman; i++) {
		h[i]->~Human();
	}
	delete[] h;

	h = tempH;
	amountHuman--;
}

void House::addHuman(const Human hum)
{
	amountHuman++;
	Human** tempH = new Human * [amountHuman];
	for (int i = 0; i < amountHuman - 1; i++) {
		tempH[i] = new Human(*h[i]);
	}
	tempH[amountHuman - 1] = new Human(hum);

	delete[] h;
	h = tempH;
}

void House::addHuman()
{
	amountHuman++;
	Human* hum = new Human;
	hum->changeHuman();
	Human** tempH = new Human * [amountHuman];
	for (int i = 0; i < amountHuman - 1; i++) {
		tempH[i] = new Human(*h[i]);
	}
	tempH[amountHuman - 1] = hum;

	delete[] h;
	h = tempH;
}

House::~House()
{
	if (h != nullptr) {
		for (int i = 0; i < amountHuman; i++) {
			h[i]->~Human();
		}
		delete[] h;
	}
}
