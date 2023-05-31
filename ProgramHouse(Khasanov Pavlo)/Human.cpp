#include "includes.h"

Human::Human(const char* fName, const char* bDate, const char* gen)
{
	if (bDate != nullptr && strlen(bDate) >= 1) {
		birthDate = new char[strlen(bDate) + 1];
		strcpy_s(birthDate, strlen(bDate) + 1, bDate);
	}
	else {
		birthDate = new char[2] {'0','\0'};
	}

	if (fName != nullptr && strlen(fName) >= 1) {
		fullName = new char[strlen(fName) + 1];
		strcpy_s(fullName, strlen(fName) + 1, fName);
	}
	else {
		fullName = new char[2] {'0', '\0'};
	}

	if (gen != nullptr && strlen(gen) >= 1) {
		gender = new char[strlen(gen) + 1];
		strcpy_s(gender, strlen(gen) + 1, gen);
	}
	else {
		gender = new char[2] {'0', '\0'};
	}
}

Human::Human(const Human& obj)
{
	// birth date:
	this->birthDate = new char[strlen(obj.birthDate) + 1];
	strcpy_s(this->birthDate, strlen(obj.birthDate) + 1, obj.birthDate);
	// name:
	this->fullName = new char[strlen(obj.fullName) + 1];
	strcpy_s(this->fullName, strlen(obj.fullName) + 1, obj.fullName);
	// gender:
	this->gender = new char[strlen(obj.gender) + 1];
	strcpy_s(this->gender, strlen(obj.gender) + 1, obj.gender);
}

void Human::displayHuman()
{
	cout << "Full name: " << fullName << endl << "Date of Birth: " << birthDate << endl << "Gender: " << gender << endl;
}

void Human::changeName(const char* fName)
{
	if (fName != nullptr && strlen(fName) >= 1) {
		delete[] fullName;
		fullName = new char[strlen(fName) + 1];
		strcpy_s(fullName, strlen(fName) + 1, fName);
	}
	else {
		return;
	}
}

void Human::changeDate(const char* bDate)
{
	if (bDate != nullptr && strlen(bDate) >= 1) {
		delete[] birthDate;
		birthDate = new char[strlen(bDate) + 1];
		strcpy_s(birthDate, strlen(bDate) + 1, bDate);
	}
	else {
		return;
	}
}

void Human::changeGender(const char* gen)
{
	if (gen != nullptr && strlen(gen) >= 1) {
		delete[] gender;
		gender = new char[strlen(gen) + 1];
		strcpy_s(gender, strlen(gen) + 1, gen);
	}
	else {
		return;
	}
}

void Human::changeHuman()
{
	char* buffer = new char[300];
	cout << "Input full name: ";
	cin.getline(buffer, 300);
	cout << endl;
	changeName(buffer);

	cout << "Input Date of Birth: ";
	cin.getline(buffer, 300);
	cout << endl;
	changeDate(buffer);
	
	cout << "Input gender: ";
	cin.getline(buffer, 300);
	cout << endl;
	changeGender(buffer);
}

Human::~Human()
{
	if (birthDate != nullptr && strlen(birthDate) >= 1)
		delete[] birthDate;
	if (fullName != nullptr && strlen(fullName) >= 1)
		delete[] fullName;
	if (gender != nullptr && strlen(gender) >= 1)
		delete[] gender;
}
