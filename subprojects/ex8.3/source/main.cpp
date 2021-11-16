#include <chrono>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <optional>
#include <range/v3/view.hpp>
#include <range/v3/numeric.hpp>
#include <range/v3/action/sort.hpp>
#include <range/v3/range/conversion.hpp>

using namespace ranges;
using namespace ranges::views;

struct Departure
{
	std::optional<std::string> expected(std::function<std::string(std::string_view)> fn) const
	{
		if (!late) return std::nullopt;
		else return fn(late.value());
	}

	std::string time{};
	std::string acronym{};
	std::string flight{};
	std::string origin{};
	std::optional<std::string> late{};
};

// acronym, name
using acronym = std::string;
using name = std::string;
using Airline = std::map<acronym, name>;
Airline airlines;

int main()
{
	auto byLine = [](std::istream& is) {
		return ranges::getlines(is)
			| transform([](auto line) { return line | ranges::views::replace('\t', ' ') | to<std::string>; })
			| transform([](auto line) { return std::stringstream(line); });
	};

	std::ifstream streamAirlines(std::filesystem::path("subprojects") / "ex8.3" / "airlines");
	airlines = byLine(streamAirlines)
		| transform([](auto sstream) -> std::pair<acronym, name> {
			std::string acronym, name;
			sstream >> acronym;
			sstream.ignore();
			std::getline(sstream, name);
			return { acronym, name };
		})
		| to<std::map>();

	std::ifstream streamDepartures(std::filesystem::path("subprojects") / "ex8.3" / "departures");
	auto departures = byLine(streamDepartures)
		| transform([](auto sstream) {
			std::string tmp;
			Departure d;
			sstream >> d.time >> d.acronym >> d.flight >> d.origin >> tmp;
			if (tmp.length()) d.late = tmp;
			return d;
		})
		| to<std::list>();


	  // ===============
	 // # Parts A & B #
	// ===============

	std::cout
		<< "Time" << '\t'
		<< "Flight" << '\t'
		<< "Airline" << '\t'
		<< "Origin" << '\t'
		<< "Late" << '\t'
		<< "Obs"
	<< std::endl;

	std::ofstream streamInfo(std::filesystem::path("subprojects") / "ex8.3" / "info");
	for (const auto& dep : departures)
	{
		std::stringstream sstream;
		sstream
			<< dep.time << '\t'
			<< dep.acronym + ' ' + dep.flight << '\t'
			<< airlines.at(dep.acronym) << '\t'
			<< dep.origin << (dep.late ? "\t" : "")
			<< dep.late.value_or("")
			<< dep.expected([&dep](std::string_view time) {
				std::tm origin;
				std::tm late;

				std::stringstream(dep.time) >> std::get_time(&origin, "%H:%M");
				std::stringstream(std::string(time)) >> std::get_time(&late, "%H:%M");

				const int seconds = (origin.tm_hour + late.tm_hour) * 3600 + (origin.tm_min + late.tm_min) * 60;

				std::stringstream ret;
				ret << std::setfill('0') << std::right << '\t'
					<< "Expected: "
					<< std::setw(2) << int(seconds/3600.0f) % 24
					<< ':'
					<< std::setw(2) << int(seconds/60.0f) % 60
					<< std::setfill(' ');

				return ret.str();
			}).value_or("");

		std::cout << sstream.str() << std::endl;
		streamInfo << sstream.str() << std::endl;
	}


	  // ==========
	 // # Part C #
	// ==========

	auto map = ranges::accumulate(
			departures
				| views::filter([](Departure d) { return d.late.has_value(); })
				| views::transform([](Departure d) -> std::pair<std::string, std::tm> {
						std::tm ret;
						std::stringstream(d.late.value()) >> std::get_time(&ret, "%H:%M");
						return { airlines.at(d.acronym), ret };
					}
				),
			std::map<std::string, std::vector<std::tm>>(),
			[](auto& map, auto pair) {
				auto& [airline, time] = pair;
				map[airline].push_back(time);
				return map;
		});

	auto sorted = map | views::transform([](const std::pair<std::string, std::vector<std::tm>>& pair) -> std::pair<std::string, int> {
			const auto& [key, vec] = pair;
			int avgSecs = ranges::accumulate(
				vec | views::transform([](std::tm time) -> int { return time.tm_hour * 3600 + time.tm_min * 60; }),
				0
			) / vec.size();

			return { key, avgSecs };
		})
		| to<std::vector>
		| actions::sort([](auto pair1, auto pair2) { return pair1.second > pair2.second; });

	auto range = sorted
		| views::transform([](auto pair) -> std::pair<std::string, std::string> {
			auto [key, seconds] = pair;
			std::stringstream ret;
			ret << std::setfill('0') << std::right
				<< std::setw(2) << int(seconds/3600.0f) % 24
				<< ':'
				<< std::setw(2) << int(seconds/60.0f) % 60
				<< std::setfill(' ');

			return { key, ret.str() };
	});


	for (const auto& [key, val] : range)
	{
		std::cout << '[' << key << ']' << ' ' << val << std::endl;
	}


	  // ==========
	 // # Part D #
	// ==========

	auto flightsByAirline = departures
		| views::group_by([](Departure a, Departure b) { return a.origin == b.origin; })
		| views::transform([](auto vec) -> std::pair<std::string, size_t> { return { vec.front().origin, (vec | to<std::vector>).size() }; });

	for (const auto& [name, total] : flightsByAirline)
	{
		std::cout << '[' << name << ']' << ' ' << total << std::endl;
	}

	return 0;
}
