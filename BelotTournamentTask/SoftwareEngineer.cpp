#include "SoftwareEngineer.h"
#include <iostream>

#pragma warning (disable: 4996)

SoftwareEngineer::SoftwareEngineer(const char* name, const char* position, unsigned salary)
{
	setName(name);
	setPosition(position);
	setSalary(salary);
}

void SoftwareEngineer::free()
{
	delete[] _name;
	delete[] _position;
	_position = _name = nullptr;
	_salary = 0;
}
void SoftwareEngineer::copyFrom(const SoftwareEngineer& other)
{
	_name = new char[strlen(other._name) + 1];
	strcpy(_name, other._name);

	_position = new char[strlen(other._position) + 1];
	strcpy(_position, other._position);

	_salary = other._salary;
}

SoftwareEngineer::SoftwareEngineer(const SoftwareEngineer& other)
{
	copyFrom(other);
}

SoftwareEngineer& SoftwareEngineer::operator=(const SoftwareEngineer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

void SoftwareEngineer::setName(const char* name)
{
	if (name == nullptr || _name == name)
		return;

	delete[] _name;
	size_t nameLen = strlen(name);
	_name = new char[nameLen + 1];
	strcpy(_name, name);

}
void SoftwareEngineer::setPosition(const char* position)
{
	if (position == nullptr || _position == position)
		return;

	delete[] _position;
	size_t posLen = strlen(position);
	_position = new char[posLen + 1];
	strcpy(_position, position);
}
void SoftwareEngineer::setSalary(unsigned salary)
{
	_salary = salary;
}

const char* SoftwareEngineer::getName() const
{
	return _name;
}
const char* SoftwareEngineer::getPosition() const
{
	return _position;
}
unsigned SoftwareEngineer::getSalary() const
{
	return _salary;
}

SoftwareEngineer::~SoftwareEngineer()
{
	free();
}