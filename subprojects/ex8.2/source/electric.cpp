#include "electric.h"

Electric::Electric(double batteryLife)
	: m_batteryLife(batteryLife)
{}

std::istream& operator>>(std::istream& istream, Electric& self)
{
	istream >> static_cast<Vehicle&>(self);
	istream >> self.m_wheels;
	istream >> self.m_batteryLife;

	return istream;
}
