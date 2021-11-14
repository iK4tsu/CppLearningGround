#pragma once

#include "vehicle.h"

class Electric : public virtual Vehicle
{
public:
	inline double batteryLife() const { return m_batteryLife; }

protected:
	Electric() = default;
	Electric(double batteryLife);

	double m_batteryLife{};
};
