#pragma once

#include <ostream>
#include <sstream>

class Date
{
public:
	constexpr Date() = default;
	constexpr Date(int day, int month, int year)
		: m_day(day)
		, m_month(month)
		, m_year(year)
	{}

	~Date() = default;
	constexpr Date(const Date& other) = default;

	friend inline std::ostream& operator<<(std::ostream& ostream, const Date& self)
	{
		ostream << self.toString();
		return ostream;
	}

	constexpr int day() const { return m_day; }
	constexpr int month() const { return m_month; }
	constexpr int year() const { return m_year; }

	inline const std::string toString() const
	{
		std::stringstream sstream;
		sstream
			<< "Date("
			<< m_day << '/'
			<< m_month << '/'
			<< m_year << ')';
		return sstream.str();
	}

private:
	int m_day{1};
	int m_month{1};
	int m_year{1970};
};
