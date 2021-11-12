#pragma once

#include "student.h"

class Fellow : public Student
{
public:
	Fellow() = default;
	Fellow(std::string name, int cc, Date birthDate);
	Fellow(
		std::string name,
		int cc,
		Date birthDate,
		Date enrolmentDate,
		double scholarship
	);

	friend std::istream& operator>>(std::istream&, Fellow&);

	inline double scholarship() const { return m_scholarship; }

	inline const std::string toString() const override
	{
		std::stringstream sstream;
		sstream
			<< "Fellow("
			<< m_name << ", "
			<< m_cc << ", "
			<< m_birthDate << ", "
			<< id() << ", "
			<< enrolmentDate() << ", "
			<< m_scholarship << ')';
		return sstream.str();
	}

private:
	double m_scholarship{1'000.0};
};
