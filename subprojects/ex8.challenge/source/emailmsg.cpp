#include "emailmsg.h"

std::istream& operator>>(std::istream& istream, EmailMsg& self)
{
	std::getline(istream, self.m_info);
	istream >> self.m_srcAddr >> self.m_dstAddr;
	return istream;
}
