#include "Team.h"

double Team::getDonation() const
{
	return (double)(_first.getSalary() + _second.getSalary()) * 0.02;
}