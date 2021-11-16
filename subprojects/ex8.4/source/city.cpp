#include "city.h"

City::City(const std::string& name, size_t population)
	: m_name(name)
	, m_population(population)
{}

City::City(std::string&& name, size_t population)
	: m_name(std::move(name))
	, m_population(population)
{}
