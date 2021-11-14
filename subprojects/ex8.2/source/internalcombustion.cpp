#include "internalcombustion.h"

InternalCombustion::InternalCombustion(double cylinderVol)
	: m_cylinderVol(cylinderVol)
{}

std::ostream& operator<<(std::ostream& ostream, const InternalCombustion& self)
{
	ostream << self.toString();
	return ostream;
}

std::istream& operator>>(std::istream& istream, InternalCombustion& self)
{
	istream >> static_cast<Vehicle&>(self);
	istream >> self.m_wheels;
	istream >> self.m_cylinderVol;

	return istream;
}
