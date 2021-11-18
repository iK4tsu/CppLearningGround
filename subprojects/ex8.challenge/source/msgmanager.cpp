#include "msgmanager.h"

void MsgManager::addUser(const User& user)
{
	m_users.insert(std::make_pair(user.email(), user));
}

void MsgManager::addUser(User&& user)
{
	m_users.insert(std::make_pair(std::string{user.email()}, std::move(user)));
}
