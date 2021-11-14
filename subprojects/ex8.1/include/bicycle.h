#pragma once

#include "vehicle.h"

class Bicycle : public Vehicle
{
public:
	enum class Type { exercise, mountain, racing, unknown };

	Bicycle() = default;
	Bicycle(unsigned short year, Color color, Type type);

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
