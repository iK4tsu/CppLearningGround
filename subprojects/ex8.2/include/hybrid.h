#pragma once

#include <istream>
#include <ostream>
#include <sstream>
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
	friend std::ostream& operator<<(std::ostream&, const Hybrid&);

	inline double emissionCO2() const override { return m_cylinderVol * 0.05; }

private:
	inline std::stringstream toSStringParams() const override
	{
		std::stringstream sstream{Vehicle::toSStringParams()};
		sstream
			<< ", " << m_batteryLife
			<< ", " << m_cylinderVol;
		return sstream;
	}
};
