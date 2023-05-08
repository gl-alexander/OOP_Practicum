#pragma once
#include "MyString.h"
#include <fstream>
class CarPart
{
	unsigned _id;
	MyString _manufacturer;
	MyString _description;
public:
	CarPart(unsigned id, const MyString& manufacturer, const MyString& desc);
	friend std::ostream& operator<<(std::ostream& os, const CarPart& carP);
};

std::ostream& operator<<(std::ostream& os, const CarPart& carP);

