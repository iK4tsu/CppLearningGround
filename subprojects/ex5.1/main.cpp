#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>

struct Stock
{
	std::string name{};
	std::string date{};
	long double openPrice{};
	long double maxPrice{};
	long double minPrice{};
	long double closePrice{};
	long double volume{};

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
	auto path = std::filesystem::path("ex5.1") / "stocks.csv";
	std::ifstream stream(path);

	std::map<std::string, std::vector<Stock>> stockmap;
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

		stockmap[stock.name].push_back(std::move(stock));
	}

	for (auto& [name, stocks] : stockmap) std::sort(stocks.begin(), stocks.end());

	std::cout
		<< "[MostTraded] "
		<< [&]() {
			std::vector<std::pair<std::string, long double>> mostTraded(stockmap.size());
			auto iter = mostTraded.begin();
			for(const auto& [name, stocks] : stockmap)
			{
				iter->first = name;
				iter->second = 0;
				for (auto& stock : stocks) iter->second += stock.volume;
				iter++;
			};

			auto& stock = *std::max_element(mostTraded.begin(), mostTraded.end(), [](const auto& pair1, const auto& pair2) {
				return pair2.second > pair1.second;
			});

			std::stringstream sstream{};
			sstream << stock.first << '(' << std::setprecision(15) << stock.second << ')';
			return sstream.str();
		}()
	<< std::endl;

	std::cout
		<< "[HighestDiff] "
		<< [&]() {
			std::vector<std::pair<std::string, long double>> highestDiff(stockmap.size());
			auto iter = highestDiff.begin();
			for(const auto& [name, stocks] : stockmap)
			{
				iter->first = name;
				iter->second = 0;
				for (auto& stock : stocks) iter->second = std::max(iter->second, stock.closePrice / stock.openPrice - 1);
				iter++;
			};

			auto& stock = *std::max_element(highestDiff.begin(), highestDiff.end(), [](const auto& pair1, const auto& pair2) {
				return pair2.second > pair1.second;
			});

			std::stringstream sstream{};
			sstream << stock.first << '(' << stock.second * 100 << "%)";
			return sstream.str();
		}()
	<< std::endl;

	std::cout
		<< "[HighestValuation] "
		<< [&]() {
			std::vector<std::pair<std::string, double>> valuations(stockmap.size());
			auto iter = valuations.begin();
			for (const auto& [name, stocks] : stockmap)
			{
				iter->first = name;
				iter++->second = stocks.back().closePrice / stocks.front().openPrice - 1;
			}

			auto& stock = *std::max_element(valuations.begin(), valuations.end(), [](const auto& valuation1, const auto& valuation2) {
				return valuation2.second > valuation1.second;
			});

			std::stringstream sstream{};
			sstream << stock.first << '(' << stock.second * 100 << "%)";
			return sstream.str();
		}()
	<< std::endl;

	std::cout
		<< "[HighestValues]\n"
		<< [&]() {
			std::stringstream sstream{};
			for (const auto& [name, stocks] : stockmap)
			{
				const Stock& stock = *std::max_element(stocks.begin(), stocks.end(), [](const auto& stock1, const auto& stock2) {
					return stock2.maxPrice > stock1.maxPrice;
				});

				sstream << std::setw(6)
					<< stock.name << "  "
					<< stock.date << "  "
					<< stock.maxPrice << '\n';
			}

			return sstream.str();
		}()
	<< std::endl;


	auto askTime = [](const std::string&& msg) {
		std::tm time;
		std::string out;
		std::stringstream sstream;
		do {
			std::cout << msg;
			std::cin >> out;
			sstream = std::stringstream(out);
			sstream >> std::get_time(&time, "%d-%b-%Y");
		} while (sstream.fail());

		return out;
	};

	std::string start(askTime("Start date (DD-Mon-YYYY) > "));
	std::string end(askTime("End date (DD-Mon-YYYY) > "));

	// start date value, end date value, total stock compagnies
	std::tuple<long double, long double, size_t> portfolio{};

	std::cout << "[Portfolio] ('!!' to finish)\n";
	std::string str;
	while ((getline(std::cin, str), str != "!!"))
	{
		if (std::regex_match(str, std::regex("[a-zA-Z]+: [0-9]+")))
		{
			std::stringstream sstream(str);
			std::string name;
			size_t shares;
			sstream >> name >> shares;

			name = name.erase(name.length() - 1);
			if (!stockmap.contains(name)) continue;

			auto front = std::find_if(stockmap[name].begin(), stockmap[name].end(), [&start](const auto& stock) { return stock.date == start; });
			auto back = std::find_if(front, stockmap[name].end(), [&end](const auto& stock) { return stock.date == end; });

			auto& [openVal, closeVal, total] = portfolio;
			openVal += front->openPrice * shares;
			closeVal += back->closePrice * shares;
			total++;
		}
	}

	const auto& [openVal, closeVal, total] = portfolio;
	std::cout << "[TotalValuation] " << (closeVal / openVal - 1) / total * 100 << "%" << std::endl;

	return 0;
}
