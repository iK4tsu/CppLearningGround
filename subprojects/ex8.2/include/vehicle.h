#pragma once

#include <istream>
#include <sstream>
#include <string_view>

class Vehicle
{
public:
	enum class Color { red, yellow, green, unknown };

	inline bool operator<(const Vehicle& other) const { return m_year < other.m_year; }

	constexpr static std::string_view strFromColor(const Color& color)
	{
		switch(color)
		{
			using enum Color;
			case red:     return "red";
			case yellow:  return "yellow";
			case green:   return "green";
			case unknown:
			default:      return "";
		}
	}

	constexpr static Color colorFromStr(const std::string_view color)
	{
		using enum Color;
		if      (color == "red")    return red;
		else if (color == "yellow") return yellow;
		else if (color == "green")  return green;
		else                        return unknown;
	}

private:
	static size_t m_globalSerial;

protected:
	Vehicle(unsigned short year, Color color, unsigned short wheels);
	Vehicle() = default;
	virtual ~Vehicle() = default;

	friend std::istream& operator>>(std::istream&, Vehicle&);

	virtual inline std::stringstream toSStringParams() const
	{
		std::stringstream sstream;
		sstream
			<< m_serialNumber << ", "
			<< m_year << ", "
			<< '"' << strFromColor(m_color) << R"(", )"
			<< m_wheels;
		return sstream;
	}

	unsigned short m_year{2'000};
	Color m_color{Color::unknown};
	unsigned short m_wheels{4};
	size_t m_serialNumber{m_globalSerial++};
};
