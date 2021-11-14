#pragma once

#include <istream>
#include "vehicle.h"

class Electric : public virtual Vehicle
{
public:
	Electric() = default;

	inline double batteryLife() const { return m_batteryLife; }

	friend std::istream& operator>>(std::istream&, Electric&);

protected:
	Electric(double batteryLife);

	double m_batteryLife{};
};
