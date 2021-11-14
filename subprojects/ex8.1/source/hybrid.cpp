#include "hybrid.h"

Hybrid::Hybrid(unsigned short year, Color color, unsigned short wheels, double cylinderVol, double batteryLife)
	: Vehicle(year, color, wheels)
	, Electric(batteryLife)
	, InternalCombustion(cylinderVol)
{}
