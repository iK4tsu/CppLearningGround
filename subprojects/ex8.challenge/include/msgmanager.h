#pragma once

#include <map>
#include <memory>
#include <vector>
#include "user.h"
#include "msg.h"

class MsgManager
{
public:

private:
	std::map<std::string, User> m_users{};
	std::vector<std::unique_ptr<Msg>> m_messages{};
};
