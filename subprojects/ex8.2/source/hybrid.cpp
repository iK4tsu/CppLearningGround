#include <iostream>
#include "hybrid.h"

Hybrid::Hybrid(unsigned short year, Color color, unsigned short wheels, double cylinderVol, double batteryLife)
	: Vehicle(year, color, wheels)
	, Electric(batteryLife)
	, InternalCombustion(cylinderVol)
{}

std::istream& operator>>(std::istream& istream, Hybrid& self)
{
	istream >> static_cast<Electric&>(self);
	istream >> self.m_cylinderVol;

	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Hybrid& self)
{
	ostream << self.toString();
	return ostream;
}
