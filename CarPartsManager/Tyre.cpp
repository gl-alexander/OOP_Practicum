#include "Tyre.h"


Tyre::Tyre(unsigned id, const MyString& manufacturer, const MyString& desc, unsigned width, unsigned profile, unsigned diameter) : CarPart(id, manufacturer, desc)
{
	_width = width;
	_profile = profile;
	_diameter = diameter;
}
std::ostream& operator<<(std::ostream& os, const Tyre& tyre)
{
	os << (const CarPart&)tyre;
	os << " - " << tyre._width << "/" << tyre._profile << "R" << tyre._diameter;
	return os;
}