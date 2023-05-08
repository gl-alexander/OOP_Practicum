#include "FuelTank.h"

insufficient_fuel_error::insufficient_fuel_error(const char* msg) : logic_error(msg) {}

FuelTank::FuelTank(unsigned id, const MyString& manufacturer, const MyString& desc, unsigned capacity, unsigned current) : CarPart(id, manufacturer, desc)
{
	_capacity = capacity;
	_current = current;
}
void FuelTank::useFuel(unsigned amount)
{
	if (_current - amount < 0)
	{
		throw insufficient_fuel_error("Not enough fuel!");
	}
	_current -= amount;
}
void FuelTank::addFuel(unsigned amount)
{
	_current += amount;
	_current = (_current <= _capacity) ? _current : _capacity;
}