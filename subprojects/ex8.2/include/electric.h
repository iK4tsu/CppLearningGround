#pragma once

#include "vehicle.h"

class Electric : public virtual Vehicle
{
public:
	Electric() = default;

	inline double batteryLife() const { return m_batteryLife; }

protected:
	Electric(double batteryLife);

	double m_batteryLife{};
};
