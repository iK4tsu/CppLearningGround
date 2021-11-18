#pragma once

#include <string>

enum class MsgType { email, mobile };
inline std::ostream& operator<<(std::ostream& ostream, const MsgType& type)
{
	switch (type)
	{
		case MsgType::email:  ostream << "email"; break;
		case MsgType::mobile:
		default:              ostream << "mobile"; break;
	}

	return ostream;
}

class Msg
{
protected:
	Msg() = default;
	Msg(const std::string&);
	Msg(std::string&&);

public:
	virtual ~Msg() = default;

	using Type = enum MsgType;

	/**
	@brief Returns the message type.
	@returns MsgType of the instance.
	*/
	virtual constexpr Type type() const = 0;

	/**
	@brief Returns the unique id of a message type.
	@returns The unique id of a message type.
	*/
	virtual size_t id() const = 0;

	inline const std::string& info() const { return m_info; }

protected:
	std::string m_info{};
};
