#include "msgmanager.h"

#include <range/v3/view.hpp>
#include <range/v3/action.hpp>

std::ostream& operator<<(std::ostream& ostream, const MsgManager& self)
{
	auto users = self.m_users
		| ranges::views::transform([](const auto& pair) { return pair.second; })
		| ranges::to<std::vector>
		| ranges::actions::sort([](const auto& lhs, const auto& rhs) { return lhs < rhs; });

	ostream << "Users list (sorted by email):\n";
	for (const auto& user : users)
		ostream << '\t' << user << '\n';

	for (const auto& msg : self.m_messages)
		ostream << msg->info() << '\n';

	return ostream;
}

void MsgManager::addUser(const User& user)
{
	m_users.insert(std::make_pair(user.email(), user));
}

void MsgManager::addUser(User&& user)
{
	m_users.insert(std::make_pair(std::string{user.email()}, std::move(user)));
}

void MsgManager::addMsg(Msg* msg)
{
	m_messages.push_back(std::unique_ptr<Msg>(msg));
}
