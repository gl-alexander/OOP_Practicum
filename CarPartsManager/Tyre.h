#pragma once
#include "CarPart.h"
class Tyre : public CarPart
{
	unsigned _width;
	unsigned _profile;
	unsigned _diameter;

public:
	Tyre(unsigned id, const MyString& manufacturer, const MyString& desc, unsigned width, unsigned profile, unsigned diameter);
	friend std::ostream& operator<<(std::ostream& os, const Tyre& tyre);
};

std::ostream& operator<<(std::ostream& os, const Tyre& tyre);
