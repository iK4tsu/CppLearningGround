#include <iostream>
#include <string>
#include "vehicle.h"

size_t Vehicle::m_globalSerial{};

Vehicle::Vehicle(unsigned short year, Color color, unsigned short wheels)
	: m_year(year)
	, m_color(color)
	, m_wheels(wheels)
{}

std::ostream& operator<<(std::ostream& ostream, const Vehicle& self)
{
	ostream << self.toString();
	return ostream;
}

std::istream& operator>>(std::istream& istream, Vehicle& self)
{
	std::string line;

	istream >> self.m_year;
	istream	>> line;

	self.m_color = Vehicle::colorFromStr(line);

	return istream;
}
