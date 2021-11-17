#include "user.h"

std::istream& operator>>(std::istream& istream, User& self)
{
	istream >> self.m_name >> self.m_email >> self.m_mobile;
	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const User& self)
{
	ostream << self.m_name << " +++ " << self.m_email << " *** " << self.m_mobile;
	return ostream;
}
