#pragma once

#include "electric.h"
#include "internalcombustion.h"

class Hybrid : public Electric, public InternalCombustion
{
public:
	Hybrid() = default;
	Hybrid(
		unsigned short year,
		Color color,
		unsigned short wheels,
		double cylinderVol,
		double batteryLife
	);

	inline double emissionCO2() const override { return m_cylinderVol * 0.05; }
};
