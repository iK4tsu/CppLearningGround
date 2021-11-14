#pragma once

#include <istream>
#include <string_view>

class Vehicle
{
public:
	enum class Color { red, yellow, green, unknown };

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

private:
	static size_t m_globalSerial;

protected:
	Vehicle(unsigned short year, Color color, unsigned short wheels);
	Vehicle() = default;
	virtual ~Vehicle() = default;

	friend std::istream& operator>>(std::istream&, Vehicle&);

	unsigned short m_year{2'000};
	Color m_color{Color::unknown};
	unsigned short m_wheels{4};
	size_t m_serialNumber{m_globalSerial++};
};
