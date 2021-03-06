#pragma once

#include <istream>
#include <ostream>
#include "vehicle.h"

class Bicycle : public Vehicle
{
public:
	enum class Type { exercise, mountain, racing, unknown };

	Bicycle() = default;
	Bicycle(unsigned short year, Color color, Type type);

	friend std::istream& operator>>(std::istream&, Bicycle&);
	friend std::ostream& operator<<(std::ostream&, const Bicycle&);

	constexpr static std::string_view strFromType(const Type& type)
	{
		switch(type)
		{
			using enum Type;
			case exercise: return "exercise";
			case mountain: return "mountain";
			case racing:   return "racing";
			case unknown:
			default:        return "";
		}
	}

private:
	Type m_type{Type::exercise};
};
