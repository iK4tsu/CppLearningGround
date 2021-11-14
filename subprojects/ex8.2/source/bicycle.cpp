#include <iostream>
#include <string>
#include "bicycle.h"

Bicycle::Bicycle(unsigned short year, Color color, Type type)
	: Vehicle(year, color, 2)
	, m_type(type)
{}

std::istream& operator>>(std::istream& istream, Bicycle& self)
{
	std::string line;

	istream >> static_cast<Vehicle&>(self);
	istream >> line;

	self.m_wheels = 2;
	self.m_type = Bicycle::typeFromStr(line);

	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Bicycle& self)
{
	ostream << self.toString();
	return ostream;
}
