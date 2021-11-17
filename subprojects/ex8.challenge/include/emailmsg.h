#pragma once

#include "msg.h"

class EmailMsg : public Msg
{
public:
	EmailMsg() = default;

	template<class T1, class T2, class T3>
	EmailMsg(T1&& info, T2&& srcAddr, T3&& dstAddr)
		: Msg(std::forward<T1>(info))
		, m_srcAddr(std::forward<T2>(srcAddr))
		, m_dstAddr(std::forward<T3>(dstAddr))
	{}

	constexpr Type type() const override { return Type::email; }

	inline size_t id() const override { return m_id; }
	inline const std::string& srcAddr() const { return m_srcAddr; }
	inline const std::string& dstAddr() const { return m_dstAddr; }

private:
	inline static size_t counter{};
	size_t m_id{counter++};
	std::string m_srcAddr{};
	std::string m_dstAddr{};
};
