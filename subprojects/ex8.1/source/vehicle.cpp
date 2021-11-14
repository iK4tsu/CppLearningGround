#include "vehicle.h"

size_t Vehicle::m_globalSerial{};

Vehicle::Vehicle(unsigned short year, Color color, unsigned short wheels)
	: m_year(year)
	, m_color(color)
	, m_wheels(wheels)
{}
