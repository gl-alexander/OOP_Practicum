#pragma once
#include "CarPart.h"
#include <exception>

class insufficient_fuel_error : public std::logic_error
{
public:
	insufficient_fuel_error(const char* msg);
};

class FuelTank : public CarPart
{
	int _capacity;
	int _current;
public:
	FuelTank(unsigned id, const MyString& manufacturer, const MyString& desc, unsigned capacity, unsigned current);
	void useFuel(unsigned amount);
	void addFuel(unsigned amount);
};

