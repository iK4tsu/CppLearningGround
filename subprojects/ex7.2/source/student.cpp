#include "student.h"

size_t Student::m_global{10'000};

Student::Student(std::string name, int cc, Date birthDate, Date enrolmentDate)
	: Person(std::move(name), cc, std::move(birthDate))
	, m_enrolmentDate(enrolmentDate)
{}
