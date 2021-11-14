#pragma once

#include <istream>
#include <sstream>
#include "vehicle.h"

class InternalCombustion : public virtual Vehicle
{
public:
	InternalCombustion() = default;

	virtual inline double emissionCO2() const
	{
		return m_cylinderVol * 0.1;
	}

	friend std::istream& operator>>(std::istream&, InternalCombustion&);

	inline std::string toString() const override
	{
		return "InternalCombustion(" + toSStringParams().str() + ')';
	}

protected:
	InternalCombustion(double cylinderVol);

	inline std::stringstream toSStringParams() const override
	{
		std::stringstream sstream{Vehicle::toSStringParams()};
		sstream << ", " << m_cylinderVol;
		return sstream;
	}

	double m_cylinderVol{};
};
