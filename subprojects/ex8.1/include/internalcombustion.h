#pragma once

#include "vehicle.h"

class InternalCombustion : public virtual Vehicle
{
public:
	virtual inline double emissionCO2() const
	{
		return m_cylinderVol * 0.1;
	}

protected:
	InternalCombustion() = default;
	InternalCombustion(double cylinderVol);

	double m_cylinderVol{};
};
