#pragma once

#include <istream>
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

	friend std::istream& operator>>(std::istream&, Hybrid&);

	inline double emissionCO2() const override { return m_cylinderVol * 0.05; }
};
