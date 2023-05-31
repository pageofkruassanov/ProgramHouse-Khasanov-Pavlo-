#include "includes.h"

Apartment::Apartment(const char* numAp)
{
	if (numAp != nullptr && strlen(numAp) >= 1) {
		this->numAp = new char[strlen(numAp) + 1];
		strcpy_s(this->numAp, strlen(numAp) + 1, numAp);

		amountHouse = 0;
		h = nullptr;
	}
}

Apartment::~Apartment()
{
	if (numAp != nullptr && strlen(numAp) >= 1) {
		delete[] numAp;
	}
	if (amountHouse > 0) {
		for (int i = 0; i < amountHouse; i++) {
			this->h[i]->~House();
		}
		delete[] h;
	}
}
