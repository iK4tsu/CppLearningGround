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
};

int main(void)
{
	auto path = std::filesystem::path("old") / "stocks.csv";
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

	// sort_heap work
	std::sort(stocks.begin(), stocks.end(), [](const Stock& stock1, const Stock& stock2) {
		std::tm time1, time2;

		/*
		kaboom

		sometimes stock1.date comes not constructed
		compiling with a sanitizer showed a buffer heap overflow
		we're accessing memory we aren't supposed to
		the reason may be because sort is writting more than it should
		*/
		std::stringstream(stock1.date) >> std::get_time(&time1, "%d-%b-%Y");
		std::stringstream(stock2.date) >> std::get_time(&time2, "%d-%b-%Y");

		return std::mktime(&time1) < std::mktime(&time2);
	});

	return 0;
}
