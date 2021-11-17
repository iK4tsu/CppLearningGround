#include <memory>
#include "msg.h"

Msg::Msg(const std::string& info)
	: m_info(info)
{}

Msg::Msg(std::string&& info)
	: m_info(std::move(info))
{}
