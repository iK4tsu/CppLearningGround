#include <iostream>
#include "fellow.h"

Fellow::Fellow(std::string name, int cc, Date birthDate)
	: Student(std::move(name), cc, std::move(birthDate))
{}

Fellow::Fellow(std::string name, int cc, Date birthDate, Date enrolmentDate, double scholarship)
	: Student(std::move(name), cc, std::move(birthDate), std::move(enrolmentDate))
	, m_scholarship(scholarship)
{}

std::istream& operator>>(std::istream& istream, Fellow& self)
{
	istream >> static_cast<Student&>(self);

	std::string line;
	std::cout << "scholarship: ";
	std::getline(istream, line);
	self.m_scholarship = std::stod(line);

	return istream;
}
