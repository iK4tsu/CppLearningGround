#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>
#include <regex>

int main(void)
{
	auto path = std::filesystem::path("ex4.3") / "words";
	std::ifstream fs(path);

	// iterate every word with consecutive characters
	auto range = std::ranges::istream_view<std::string>(fs)
		| std::ranges::views::filter([](std::string str) { return std::regex_search(str, std::regex(R"((.)\1+)")); });

	size_t sum = 0;
	for (auto word : range) sum++;
	std::cout << sum << std::endl;

	return 0;
}
