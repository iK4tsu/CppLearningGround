#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

struct Stock
{
	std::string name{};
	std::string date{};
	long double openPrice{};
	long double maxPrice{};
	long double minPrice{};
	long double closePrice{};
	long double volume{};

	/*
	Overriding the less operator seems to fix the issue
	But why? The logic is the same
	Sort should not have a completely new behaviour by calling the struct's comparison method
	*/
	bool operator<(const Stock& other)
	{
		std::tm time1{};
		std::tm time2{};

		std::stringstream(date) >> std::get_time(&time1, "%d-%b-%Y");
		std::stringstream(other.date) >> std::get_time(&time2, "%d-%b-%Y");

		return std::mktime(&time1) < std::mktime(&time2);
	}
};

int main(void)
{
	auto path = std::filesystem::path("new") / "stocks.csv";
	std::ifstream stream(path);

	std::vector<Stock> stocks;
	for (std::string line; std::getline(stream, line);)
	{
		std::replace(line.begin(), line.end(), ',', ' ');
		std::stringstream sstream(line);

		Stock stock{};
		sstream
			>> stock.name
			>> stock.date
			>> stock.openPrice
			>> stock.maxPrice
			>> stock.minPrice
			>> stock.closePrice
			>> stock.volume;

		stocks.push_back(std::move(stock));
	}

	std::sort(stocks.begin(), stocks.end());

	return 0;
}
