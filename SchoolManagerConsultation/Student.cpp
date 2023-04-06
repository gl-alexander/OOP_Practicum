#include "Student.h"
#include <iostream>
#include <fstream>

#pragma warning (disable : 4996)

namespace
{
	void copyDynamicCharArr(char*& arr, const char* str)
	{
		//delete[] arr;
		arr = new char[strlen(str)];
		strcpy(arr, str);
	}
}

void Student::copyFrom(const Student& other)
{
	copyFirstName(other.firstName);
	copyLastName(other.lastName);
}
void Student::free()
{
	delete[] firstName;
	delete[] lastName;

	firstName = lastName = nullptr;
}
void Student::copyFirstName(const char* other)
{
	copyDynamicCharArr(this->firstName, other);
}
void Student::copyLastName(const char* other)
{
	copyDynamicCharArr(this->lastName, other);
}


Student::Student(const char* firstName, const char* lastName)
{
	copyFirstName(firstName);
	copyLastName(lastName);
}
Student::Student(const Student& other)
{
	copyFrom(other);
}
Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}
Student::~Student()
{
	free();
}

void Student::setFirstName(const char* firstName)
{
	copyFirstName(firstName);
}
void Student::setLastName(const char* lastName)
{
	copyLastName(lastName);
}

const char* Student::getFirstName() const
{
	return firstName;
}
const char* Student::getLastName() const
{
	return lastName;
}

void Student::saveToFile(std::ofstream& ofs) const
{
	std::cout << "member function save to file";
	int firstNameLen = strlen(firstName);
	int lastNameLen = strlen(lastName);

	ofs.write((const char*)&firstNameLen, sizeof(int));
	ofs.write(firstName, firstNameLen);

	ofs.write((const char*)&lastNameLen, sizeof(int));
	ofs.write(lastName, lastNameLen);
}
void Student::readFromFile(std::ifstream& ifs)
{
	
	int firstNameLen;

	ifs.read((char*)&firstNameLen, sizeof(int));
	firstName = new char[firstNameLen + 1];
	ifs.read(firstName, firstNameLen);

	int lastNameLen;

	ifs.read((char*)&lastNameLen, sizeof(int));
	lastName = new char[lastNameLen + 1];
	ifs.read(lastName, lastNameLen);

	firstName[firstNameLen] = '\0';
	lastName[lastNameLen] = '\0';

}