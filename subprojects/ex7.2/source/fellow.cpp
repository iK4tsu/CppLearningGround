#include "fellow.h"

Fellow::Fellow(std::string name, int cc, Date birthDate)
	: Student(std::move(name), cc, std::move(birthDate))
{}

Fellow::Fellow(std::string name, int cc, Date birthDate, Date enrolmentDate, double scholarship)
	: Student(std::move(name), cc, std::move(birthDate), std::move(enrolmentDate))
	, m_scholarship(scholarship)
{}
