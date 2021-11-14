#pragma once

#include "vehicle.h"

class InternalCombustion : public virtual Vehicle
{
public:
	InternalCombustion() = default;

	virtual inline double emissionCO2() const
	{
		return m_cylinderVol * 0.1;
	}

protected:
	InternalCombustion(double cylinderVol);

	double m_cylinderVol{};
};
