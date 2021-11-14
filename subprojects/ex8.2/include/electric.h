#pragma once

#include <istream>
#include <ostream>
#include <sstream>
#include "vehicle.h"

class Electric : public virtual Vehicle
{
public:
	Electric() = default;

	inline double batteryLife() const { return m_batteryLife; }

	friend std::istream& operator>>(std::istream&, Electric&);
	friend std::ostream& operator<<(std::ostream&, const Electric&);

	inline std::string toString() const override
	{
		return "Electric(" + toSStringParams().str() + ')';
	}

protected:
	Electric(double batteryLife);

	inline std::stringstream toSStringParams() const override
	{
		std::stringstream sstream{Vehicle::toSStringParams()};
		sstream << ", " << m_batteryLife;
		return sstream;
	}

	double m_batteryLife{};
};
