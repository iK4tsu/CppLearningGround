#pragma once

#include <iostream>
#include <ostream>
#include "msg.h"

class MobileMsg : public Msg
{
public:
	MobileMsg() = default;

	/**
	@brief Constructs a new EmailMsg instance.
	@tparam T1 Type implicitly convertible to `std::string`.
	@tparam T2 Type implicitly convertible to `std::string`.
	@tparam T2 Type implicitly convertible to `std::string`.
	@param info Msg body content.
	@param srcMobile EmailMsg source phone number.
	@param dstMobile EmailMsg destination phone number.
	*/
	template<class T1, class T2, class T3>
	MobileMsg(T1&& info, T2&& srcMobile, T3&& dstMobile)
		: Msg(std::forward<T1>(info))
		, m_srcMobile(std::forward<T2>(srcMobile))
		, m_dstMobile(std::forward<T3>(dstMobile))
	{}

	friend std::istream& operator>>(std::istream&, MobileMsg&);
	friend std::ostream& operator<<(std::ostream&, const MobileMsg&);

	/*! @copydoc Msg::type */
	constexpr Type type() const override { return Type::mobile; }

	/*! @copydoc Msg::id */
	inline size_t id() const override { return m_id; }
	inline const std::string& srcMobile() const { return m_srcMobile; }
	inline const std::string& dstMobile() const { return m_dstMobile; }

private:
	inline static size_t counter{100};
	size_t m_id{counter++};
	std::string m_srcMobile{};
	std::string m_dstMobile{};
};
