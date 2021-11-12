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

private:
	double m_scholarship{1'000.0};
};
