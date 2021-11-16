#include "country.h"

void Country::insert(const District& district)
{
	m_districts.insert(district);
}

void Country::insert(District&& district)
{
	m_districts.insert(std::move(district));
}
