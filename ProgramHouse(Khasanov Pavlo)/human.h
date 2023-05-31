#pragma once
#include "includes.h"
class Human
{
private:
	char* birthDate;
	char* fullName;
	char* gender;
public:
	Human() : Human("not specified", "not specified", "not specified") {};
	Human(const char* fName) : Human(fName, "not specified", "not specified") {};
	Human(const char* fName, const char* bDate) : Human(fName, bDate, "not specified") {};
	Human(const char* fName, const char* bDate, const char* gen);
	
	Human(const Human& obj);

	void displayHuman();
	void changeName(const char* fName);
	void changeDate(const char* bDate);
	void changeGender(const char* gen);
	void changeHuman();

	~Human();

};

