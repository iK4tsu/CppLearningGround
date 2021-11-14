#include <iostream>
#include <vector>
#include "bicycle.h"
#include "hybrid.h"

int main()
{
	std::cout << "Insertion for Bicycle:\nyear,color,type\n";
	Bicycle b;
	std::cin >> b;
	std::cout << b << std::endl;

	std::cout << "\nInsertion for Hybrid:\nyear,color,number of wheels,battery life,cylinder volume\n";
	Hybrid h;
	std::cin >> h;
	std::cout << h << std::endl;

	//~ Available bikes
	std::vector<Bicycle> bikes;
	bikes.push_back(Bicycle(2012, Bicycle::Color::red, Bicycle::Type::mountain));
	bikes.push_back(Bicycle(2005, Bicycle::Color::yellow, Bicycle::Type::racing));
	bikes.push_back(Bicycle(2012, Bicycle::Color::red, Bicycle::Type::mountain));	//another identical bike (not the same bike)

	sort(bikes.begin(), bikes.end());
	std::cout << "\nBikes:\n";
	for(auto b: bikes)
	std::cout << b << std::endl;

	//Hybrid vehicles
	std::vector<Hybrid> hv;
	hv.push_back(Hybrid(2018, Bicycle::Color::red, 4, 1800, 100));
	hv.push_back(Hybrid(2016, Bicycle::Color::green, 4, 1600, 120));
	hv.push_back(Hybrid(2016, Bicycle::Color::yellow, 4, 1900, 90));

	sort(hv.begin(), hv.end());
	std::cout << "\nHybrid vehicles:\n";
	for(auto h: hv)
	std::cout << h << std::endl;


	return 0;
}
