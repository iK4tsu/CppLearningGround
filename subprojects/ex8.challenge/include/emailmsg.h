#pragma once

#include <iostream>
#include <ostream>
#include "msg.h"

class EmailMsg : public Msg
{
public:
	EmailMsg() = default;

	/**
	@brief Constructs a new EmailMsg instance.
	@tparam T1 Type implicitly convertible to `std::string`.
	@tparam T2 Type implicitly convertible to `std::string`.
	@tparam T2 Type implicitly convertible to `std::string`.
	@param info Msg body content.
	@param srcAddr EmailMsg source address.
	@param dstAddr EmailMsg destination address.
	*/
	template<class T1, class T2, class T3>
	EmailMsg(T1&& info, T2&& srcAddr, T3&& dstAddr)
		: Msg(std::forward<T1>(info))
		, m_srcAddr(std::forward<T2>(srcAddr))
		, m_dstAddr(std::forward<T3>(dstAddr))
	{}

	friend std::istream& operator>>(std::istream&, EmailMsg&);
	friend std::ostream& operator<<(std::ostream&, const EmailMsg&);

	/*! @copydoc Msg::type */
	constexpr Type type() const override { return Type::email; }

	/*! @copydoc Msg::id */
	inline size_t id() const override { return m_id; }
	inline const std::string& srcAddr() const { return m_srcAddr; }
	inline const std::string& dstAddr() const { return m_dstAddr; }

private:
	inline static size_t counter{};
	size_t m_id{counter++};
	std::string m_srcAddr{};
	std::string m_dstAddr{};
};
