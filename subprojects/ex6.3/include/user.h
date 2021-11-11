#pragma once

#include <cstddef>
#include <string>

class User
{
public:
	User() = default;
	User(size_t nMec, std::string name, std::string course);

	constexpr bool operator<(const User& other) const { return m_nMec < other.m_nMec; }

	inline size_t nMec() const { return m_nMec; }
	inline std::string_view course() const { return m_course; }
	inline std::string_view name() const { return m_name; }

private:
	size_t m_nMec{};
	std::string m_course{};
	std::string m_name{};
};
