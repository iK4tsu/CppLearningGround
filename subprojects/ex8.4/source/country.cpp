#include "country.h"

void Country::insert(const District& district)
{
	m_districts.insert(district);
}

void Country::insert(District&& district)
{
	m_districts.insert(std::move(district));
}

std::ostream& operator<<(std::ostream& ostream, const Country& self)
{
	ostream
		<< "Country: " << self.m_name << '\n'
		<< "Capital: " << self.m_capital.name() << '\n'
		<< "\tPopulation: " << self.m_capital.population() << '\n'
		<< "Districts: " << '\n';

	for (const District& district : self.m_districts)
	{
		ostream
			<< "\tDistrict: " << district.name() << '\n'
			<< "\t\tCapital: " << district.capital().name() << '\n'
			<< "\t\t\tPopulation: " << district.capital().population() << '\n'
			<< "\t\tPopulation: " << district.population() << '\n';
	}

	return ostream;
}
