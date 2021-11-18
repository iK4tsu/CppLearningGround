#pragma once

#include <map>
#include <memory>
#include <vector>
#include "user.h"
#include "msg.h"

class MsgManager
{
public:
	friend std::ostream& operator<<(std::ostream&, const MsgManager&);

	void addUser(const User&);
	void addUser(User&&);
	void addMsg(Msg* msg);

private:
	std::map<std::string, User> m_users{};
	std::vector<std::unique_ptr<Msg>> m_messages{};
};
