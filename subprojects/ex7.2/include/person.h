#pragma once

#include <string>
#include <string_view>
#include "date.h"

class Person
{
public:
	Person() = default;
	Person(std::string name, int cc, Date date);
	Person(const Person&) = default;
	virtual ~Person() = default;

	inline std::string_view name() const { return m_name; }
	inline int cc() const { return m_cc; }
	inline const Date& birthDate() const { return m_birthDate; }

protected:
	std::string m_name{};
	int m_cc{};
	Date m_birthDate{};
};
