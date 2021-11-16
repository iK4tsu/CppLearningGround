#pragma once

#include <cstddef>
#include <string>

class City
{
public:
	City() = default;
	City(const std::string&, size_t);
	City(std::string&&, size_t);

	inline std::string_view name() const { return m_name; }
	inline size_t population() const { return m_population; }

private:
	std::string m_name{};
	size_t m_population{};
};
