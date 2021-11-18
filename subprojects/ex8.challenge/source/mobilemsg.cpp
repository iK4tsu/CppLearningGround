#include "mobilemsg.h"

std::istream& operator>>(std::istream& istream, MobileMsg& self)
{
	std::getline(istream, self.m_info);
	istream >> self.m_srcMobile >> self.m_dstMobile;
	return istream;
}
