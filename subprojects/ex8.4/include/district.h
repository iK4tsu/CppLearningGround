#pragma once

#include <type_traits>
#include "city.h"
#include "traits.hpp"

class District
{
public:
	District() = default;

	template<class T1, class T3>
	District(T1&& name, size_t population, T3&& capital)
		: m_name{std::forward<T1>(name)}
		, m_population{population}
		, m_capital{std::forward<T3>(capital)}
	{
		static_assert(is_convertible_unqual<T1, std::string>, "Type T1 must be convertible to 'std::string'");
		static_assert(is_same_unqual<T3, City>, "Type T3 must be 'City'");
	}

	inline bool operator<(const District& rhs) const { return m_name < rhs.m_name; }

	inline std::string_view name() const { return m_name; }
	inline size_t population() const { return m_population; }
	inline const City& capital() const { return m_capital; }

private:
	std::string m_name{};
	size_t m_population{};
	City m_capital{};
};
