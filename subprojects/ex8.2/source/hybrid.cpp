#include <iostream>
#include <string>
#include "hybrid.h"

Hybrid::Hybrid(unsigned short year, Color color, unsigned short wheels, double cylinderVol, double batteryLife)
	: Vehicle(year, color, wheels)
	, Electric(batteryLife)
	, InternalCombustion(cylinderVol)
{}

std::istream& operator>>(std::istream& istream, Hybrid& self)
{
	istream >> static_cast<Vehicle&>(self);

	std::string line;

	std::cout << "Wheels: ";
	std::getline(istream, line);
	self.m_wheels = unsigned(std::stoul(line));

	std::cout << "Battery life: ";
	std::getline(istream, line);
	self.m_batteryLife = std::stod(line);

	std::cout << "Cylinder volume ";
	std::getline(istream, line);
	self.m_cylinderVol = std::stod(line);

	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Hybrid& self)
{
	ostream
		<< "Hybrid("
		<< self.m_year << ", "
		<< Vehicle::strFromColor(self.m_color) << ", "
		<< self.m_wheels << ", "
		<< self.m_batteryLife << ", "
		<< self.m_cylinderVol
		<< ')';
	return ostream;
}
