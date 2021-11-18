#include "msgmanager.h"

#include <filesystem>
#include <fstream>
#include <range/v3/view.hpp>
#include <range/v3/action.hpp>
#include <sstream>
#include "emailmsg.h"
#include "mobilemsg.h"

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

void MsgManager::emailsFrom(std::string_view email) const
{
	auto emails = m_messages
		| ranges::views::filter([](const auto& msg) { return msg->type() == MsgType::email; })
		| ranges::views::transform([](const auto& msg) { return static_cast<EmailMsg*>(msg.get()); })
		| ranges::views::filter([email](const auto& msg) { return msg->srcAddr() == email; });

	for (const auto email : emails)
		std::cout << "\tto: " << m_users.at(std::string{email->dstAddr()}) << ": " << email->info() << std::endl;
}

void MsgManager::saveTo(std::string_view filename) const
{
	auto path = std::filesystem::path("subprojects")/"ex8.challenge"/filename;
	std::ofstream savefile(path);

	auto filterMap = []<MsgType type, class T>() {
		using namespace ranges::views;
		return filter([](const auto& msg) { return msg->type() == type; })
		| transform([](const auto& msg) { return static_cast<T&>(*msg); });
	};

	auto users = m_users | ranges::views::transform([](const auto& pair) { return pair.second; });
	auto emails = m_messages | filterMap.operator()<MsgType::email, EmailMsg>();
	auto mobiles = m_messages | filterMap.operator()<MsgType::mobile, MobileMsg>();

	for (const auto& user : users)
		savefile << "user " << user.name() << ' ' << user.email() << ' ' << user.mobile() << '\n';

	for (const auto& email : emails)
		savefile << "email " << ' ' << email.srcAddr() << ' ' << email.dstAddr() << ' ' << email.info() << '\n';

	for (const auto& mobile : mobiles)
		savefile << "mobile " << ' ' << mobile.srcMobile() << ' ' << mobile.dstMobile() << ' ' << mobile.info() << '\n';
}

void MsgManager::loadFrom(std::string_view filename)
{
	auto path = std::filesystem::path("subprojects")/"ex8.challenge"/filename;
	std::ifstream loadfile(path);

	for (std::string line; std::getline(loadfile, line);)
	{
		std::stringstream sstream(std::move(line));
		sstream >> line;
		if (line == "user")
		{
			User user;
			sstream >> user;
			addUser(std::move(user));
		}
		else
		{
			std::string info;
			std::string src;
			std::string dst;

			sstream >> src >> dst;
			std::getline(sstream, info);

			if (line == "email")
				m_messages.push_back(std::make_unique<EmailMsg>(std::move(info), std::move(src), std::move(dst)));
			else
				m_messages.push_back(std::make_unique<MobileMsg>(std::move(info), std::move(src), std::move(dst)));
		}
	}
}
