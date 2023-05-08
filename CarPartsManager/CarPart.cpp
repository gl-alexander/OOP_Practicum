#include "CarPart.h"

CarPart::CarPart(unsigned id, const MyString& manufacturer, const MyString& desc)
{
	_id = id;
	_manufacturer = manufacturer;
	_description = desc;
}
std::ostream& operator<<(std::ostream& os, const CarPart& carP)
{
	os << "(" << carP._id << ") by " << carP._manufacturer << " - " << carP._description;
	return os;
} 
