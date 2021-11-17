#include "emailmsg.h"

std::istream& operator>>(std::istream& istream, EmailMsg& self)
{
	std::getline(istream, self.m_info);
	istream >> self.m_srcAddr >> self.m_dstAddr;
	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const EmailMsg& self)
{
	ostream
		<< "Email " << self.m_id
		<< " from " << self.m_srcAddr
		<< " to " << self.m_dstAddr
		<< ": " << self.m_info;
	return ostream;
}

