#include "../include/user.h"

User::User(size_t nMec, std::string name, std::string course)
	: m_nMec(nMec)
	, m_course(std::move(course))
	, m_name(std::move(name))
{}
