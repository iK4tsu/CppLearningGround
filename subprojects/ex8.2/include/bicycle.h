#pragma once

#include <istream>
#include <ostream>
#include <sstream>
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
			default:       return "";
		}
	}

	constexpr static Type typeFromStr(std::string_view type)
	{
		using enum Type;
		if      (type == "exercise") return exercise;
		else if (type == "mountain") return mountain;
		else if (type == "racing")   return racing;
		else                         return unknown;
	}

	inline std::string toString() const override
	{
		return "Bicycle(" + toSStringParams().str() + ')';
	}

private:
	inline std::stringstream toSStringParams() const override
	{
		std::stringstream sstream{Vehicle::toSStringParams()};
		sstream << R"(, ")" << strFromType(m_type) << '"';
		return sstream;
	}

	Type m_type{Type::exercise};
};
