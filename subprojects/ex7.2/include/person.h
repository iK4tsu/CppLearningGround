#pragma once

#include <string>
#include <string_view>
#include <sstream>
#include "date.h"

class Person
{
public:
	Person() = default;
	Person(std::string name, int cc, Date date);
	Person(const Person&) = default;
	virtual ~Person() = default;

	inline friend std::ostream& operator<<(std::ostream& ostream, const Person& self)
	{
		ostream << self.toString();
		return ostream;
	}

	inline std::string_view name() const { return m_name; }
	inline int cc() const { return m_cc; }
	inline const Date& birthDate() const { return m_birthDate; }

	virtual inline const std::string toString() const
	{
		std::stringstream sstream;
		sstream
			<< "Person("
			<< m_name << ", "
			<< m_cc << ", "
			<< m_birthDate << ')';
		return sstream.str();
	}

protected:
	std::string m_name{};
	int m_cc{};
	Date m_birthDate{};
};
