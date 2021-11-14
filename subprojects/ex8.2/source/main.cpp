#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "bicycle.h"
#include "electric.h"
#include "hybrid.h"
#include "internalcombustion.h"

template<class V>
void readVehicles(std::vector<V>& vec, std::string_view fileName)
{
	auto path = std::filesystem::path("subprojects") / "ex8.2" / fileName;
	std::ifstream file(path);

	while (!file.eof())
	{
		V vehicle;
		std::string line;
		std::getline(file, line);
		std::replace(line.begin(), line.end(), ',', ' ');
		std::stringstream sstream(std::move(line));

		sstream >> vehicle;
		vec.push_back(std::move(vehicle));
	}
}

struct CmpVehiclePtr
{
	bool operator()(const Vehicle* a, const Vehicle* b) const
	{
		return a->serialNumber() < b->serialNumber();
	}
};

int main()
{
	std::vector<Bicycle> bikes;
	std::vector<Electric> electrics;
	std::vector<InternalCombustion> icombustions;
	std::vector<Hybrid> hybrids;

	readVehicles(bikes, "bicycles.csv");
	readVehicles(electrics, "electric.csv");
	readVehicles(icombustions, "internal_combustion.csv");
	readVehicles(hybrids, "hybrid.csv");

	std::sort(bikes.begin(), bikes.end());
	std::sort(electrics.begin(), electrics.end());
	std::sort(icombustions.begin(), icombustions.end());
	std::sort(hybrids.begin(), hybrids.end());

	std::set<Vehicle*, CmpVehiclePtr> available;
	std::set<Vehicle*, CmpVehiclePtr> rented;

	for (auto& v : bikes) available.insert(&v);
	for (auto& v : electrics) available.insert(&v);
	for (auto& v : icombustions) available.insert(&v);
	for (auto& v : hybrids) available.insert(&v);

	auto printVehicles = [](std::set<Vehicle*, CmpVehiclePtr>& vehicles, std::string_view name)
	{
		std::map<size_t, Vehicle*> ret;
		for (Vehicle* v : vehicles)
		if (typeid(*v).name() == name)
		{
			ret[v->serialNumber()] = v;
			std::cout << *v << std::endl;
		}
		return ret;
	};

	bool over{false};
	while (!over)
	{
		enum Option { exit, rentVehicle, returnVehicle, listAvailable, listRented };
		std::cout
			<< "[1] Rent a vehicle\n"
			<< "[2] Return a vehicle\n"
			<< "[3] List available vehicles\n"
			<< "[4] List rented vehicles\n"
			<< "[0] Exit\n"
			<< "> ";

		std::string line;
		std::getline(std::cin, line);
		Option option = (Option) std::stoi(line);

		auto vehicleName = [&line]() mutable -> std::string_view {
			std::cout
				<< "[1] Bicycle\n"
				<< "[2] Internal combustion\n"
				<< "[3] Electric\n"
				<< "[4] Hybrid\n"
				<< "> ";

			std::getline(std::cin, line);
			switch (std::stoi(line))
			{
				case 1:  return typeid(Bicycle).name(); break;
				case 2:  return typeid(InternalCombustion).name(); break;
				case 3:  return typeid(Electric).name(); break;
				case 4:
				default: return typeid(Hybrid).name(); break;
			}
		};

		switch (option)
		{
			default:
			case exit:
				over = true;
				break;

			case rentVehicle:
			{
				auto map = printVehicles(available, vehicleName());
				std::cout << "> ";
				std::getline(std::cin, line);
				size_t id = std::stoul(line);
				rented.insert(std::move(available.extract(map.at(id))));
				break;
			}

			case returnVehicle:
			{
				auto map = printVehicles(rented, vehicleName());
				std::cout << "> ";
				std::getline(std::cin, line);
				size_t id = std::stoul(line);
				available.insert(std::move(rented.extract(map.at(id))));
				break;
			}

			case listAvailable:
				printVehicles(available, vehicleName());
				std::cout << "[Press ENTER to continue]";
				std::cin.ignore();
				break;

			case listRented:
				printVehicles(rented, vehicleName());
				std::cout << "[Press ENTER to continue]";
				std::cin.ignore();
				break;
		}
	}

	return 0;
}
