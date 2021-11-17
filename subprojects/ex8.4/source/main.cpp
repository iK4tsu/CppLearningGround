#include <iostream>
#include <set>
#include "city.h"
#include "district.h"
#include "country.h"

int main()
{
	City cid1("Szohod", 31212);
	City cid2("Wadesdah", 23423);
	City cid3("BedRock", 234234);

	District est1("North Borduria", 223133, std::move(cid1));
	District est2("South Borduria", 84321, std::move(cid2));

	Country p1("Borduria", est1.capital());
	Country p2("Aurelia", est2.capital());
	Country p3("Khemed", std::move(cid3));
	Country p4("Atlantis", City("Lisbon", 999999));

	std::cout << "insert" << std::endl;

	p1.insert(std::move(est1));
	p2.insert(std::move(est2));
	p2.insert(District("Afrinia", 232475, City("Laurania", 30000)));
	p2.insert(District("Eriador", 100000, City("RedRiver", 5555)));

	std::cout << "insert" << std::endl;

	std::set<Country> org;
	org.insert(std::move(p1));
	org.insert(std::move(p2));
	org.insert(std::move(p3));
	org.insert(std::move(p4));

	std::cout << "----Iterar sobre o conjunto" << std::endl;
	for(const auto& c : org)
		std::cout << c << std::endl;

	return 0;
}
