#include <iostream>
#include <string>
#include "bicycle.h"

Bicycle::Bicycle(unsigned short year, Color color, Type type)
	: Vehicle(year, color, 2)
	, m_type(type)
{}

std::istream& operator>>(std::istream& istream, Bicycle& self)
{
	istream >> static_cast<Vehicle&>(self);

	self.m_wheels = 2;

	std::string line;
	for (int i = 0; i < static_cast<int>(Bicycle::Type::racing); i++)
		std::cout
			<< '['
			<< i
			<< "] "
			<< self.strFromType(static_cast<Bicycle::Type>(i))
			<< '\n';
	std::cout << "> ";
	std::getline(istream, line);
	self.m_type = static_cast<Bicycle::Type>(std::stoi(line));

	return istream;
}
