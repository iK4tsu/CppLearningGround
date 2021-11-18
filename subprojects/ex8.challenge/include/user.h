#pragma once

#include <memory>
#include <istream>
#include <ostream>
#include <string>

class User
{
public:
	User() = default;

	/**
	@brief Constructs a new User instance.
	@tparam T1 Type implicitly convertible to `std::string`.
	@tparam T2 Type implicitly convertible to `std::string`.
	@tparam T2 Type implicitly convertible to `std::string`.
	@param name User name.
	@param email User email.
	@param mobile User phone number.
	*/
	template<class T1, class T2, class T3>
	User(T1&& name, T2&& email, T3&& mobile)
		: m_name(std::forward<T1>(name))
		, m_email(std::forward<T2>(email))
		, m_mobile(std::forward<T3>(mobile))
	{}

	friend std::istream& operator>>(std::istream&, User&);
	friend std::ostream& operator<<(std::ostream&, const User&);

	/**
	@brief Comparison operator of the User's email by lexicographic order.
	@param rhs The User's email to compare.
	@returns True if the User's email is lower than the `rhs`'s email by
	lexicographic order.
	*/
	inline bool operator<(const User& rhs) const { return m_email < rhs.m_email; }

	inline const std::string& name() const { return m_name; }
	inline const std::string& email() const { return m_email; }
	inline const std::string& mobile() const { return m_mobile; }

	inline void name(std::string&& name) { m_name = std::move(name); }
	inline void email(std::string&& email) { m_email = std::move(email); }
	inline void mobile(std::string&& mobile) { m_mobile = std::move(mobile); }

private:
	std::string m_name{};
	std::string m_email{};
	std::string m_mobile{};
};
