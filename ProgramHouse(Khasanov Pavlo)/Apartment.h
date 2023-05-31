#pragma once
#include "includes.h"
class Apartment
{
private:
	char* numAp;
	int amountHouse;
	House** h;
public:

	Apartment(const char* numAp);

	void addApartment();


	~Apartment();
};


