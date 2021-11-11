#include "person.h"

Person::Person(std::string name, int cc, Date date)
	: m_name(std::move(name))
	, m_cc(cc)
	, m_birthDate(date)
{}
