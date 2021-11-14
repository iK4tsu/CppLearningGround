#include <iostream>
#include <string>
#include "vehicle.h"

size_t Vehicle::m_globalSerial{};

Vehicle::Vehicle(unsigned short year, Color color, unsigned short wheels)
	: m_year(year)
	, m_color(color)
	, m_wheels(wheels)
{}

std::istream& operator>>(std::istream& istream, Vehicle& self)
{
	std::string line;

	std::cout << "Year: ";
	std::getline(istream, line);
	self.m_year = unsigned(std::stoul(line));

	for (int i = 0; i < static_cast<int>(Vehicle::Color::unknown); i++)
		std::cout
			<< '['
			<< i
			<< "] "
			<< self.strFromColor(static_cast<Vehicle::Color>(i))
			<< '\n';
	std::cout << "> ";
	std::getline(istream, line);
	self.m_color = static_cast<Vehicle::Color>(std::stoi(line));

	return istream;
}
