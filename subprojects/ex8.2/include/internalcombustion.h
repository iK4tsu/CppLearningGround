#pragma once

#include <istream>
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

protected:
	InternalCombustion(double cylinderVol);

	double m_cylinderVol{};
};
