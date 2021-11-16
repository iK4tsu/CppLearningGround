#pragma once

#include <set>
#include "city.h"
#include "district.h"

class Country
{
public:
	Country() = default;

	template<class T1, class T2>
	Country(T1&& name, T2&& capital)
		: m_name{std::forward<T1>(name)}
		, m_capital(std::forward<T2>(capital))
	{}

	void insert(const District&);
	void insert(District&&);

private:
	std::string m_name{};
	City m_capital{};
	std::set<District> m_districts{};
};
