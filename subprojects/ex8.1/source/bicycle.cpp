#include "bicycle.h"

Bicycle::Bicycle(unsigned short year, Color color, Type type)
	: Vehicle(year, color, 2)
	, m_type(type)
{}
