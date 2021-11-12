#pragma once

#include <istream>
#include <ostream>
#include <ctime>
#include "person.h"

class Student : public Person
{
public:
	using Person::Person;
	Student() = default;
	Student(std::string name, int cc, Date birthDate, Date enrolmentDate);
	Student(const Student&) = default;
	~Student() = default;

	friend std::istream& operator>>(std::istream&, Student&);

	inline size_t id() const { return m_id; }
	inline const Date& enrolmentDate() const { return m_enrolmentDate; }

	inline const std::string toString() const override
	{
		std::stringstream sstream;
		sstream
			<< "Student("
			<< m_name << ", "
			<< m_cc << ", "
			<< m_birthDate << ", "
			<< m_id << ", "
			<< m_enrolmentDate << ')';
		return sstream.str();
	}

private:
	static size_t m_global;
	size_t m_id{m_global++};
	Date m_enrolmentDate{[] {
		const auto now = time(0);
		const auto& local = *localtime(&now);
		return Date(local.tm_mday, 1 + local.tm_mon, 1900 + local.tm_year);
	} ()};
};
