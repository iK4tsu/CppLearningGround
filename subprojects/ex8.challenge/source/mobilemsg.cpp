#include "mobilemsg.h"

std::istream& operator>>(std::istream& istream, MobileMsg& self)
{
	std::getline(istream, self.m_info);
	istream >> self.m_srcMobile >> self.m_dstMobile;
	return istream;
}

std::ostream& operator<<(std::ostream& ostream, const MobileMsg& self)
{
	ostream
		<< "MobileMsg " << self.m_id
		<< " from " << self.m_srcMobile
		<< " to " << self.m_dstMobile
		<< ": " << self.m_info;
	return ostream;
}
