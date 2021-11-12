#include <iomanip>
#include <iostream>
#include "student.h"

size_t Student::m_global{10'000};

Student::Student(std::string name, int cc, Date birthDate, Date enrolmentDate)
	: Person(std::move(name), cc, std::move(birthDate))
	, m_enrolmentDate(enrolmentDate)
{}

std::istream& operator>>(std::istream& istream, Student& self)
{
	std::cout << "Name: ";
	std::getline(istream, self.m_name);

	std::string line;
	std::tm time;

	std::cout << "CC: ";
	std::getline(istream, line);
	self.m_cc = std::stoi(line);

	std::cout << "Birth date [DD-Mon-YYYY]: ";
	std::getline(istream, line);
	std::stringstream{line} >> std::get_time(&time, "%d-%b-%Y");
	self.m_birthDate = Date(time.tm_mday, 1 + time.tm_mon, 1900 + time.tm_year);

	std::cout << "Enrolnment date [DD-Mon-YYYY]: ";
	std::getline(istream, line);
	std::stringstream{line} >> std::get_time(&time, "%d-%b-%Y");
	self.m_enrolmentDate = Date(time.tm_mday, 1 + time.tm_mon, 1900 + time.tm_year);

	return istream;
}
