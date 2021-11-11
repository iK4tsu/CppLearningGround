#include <filesystem>
#include <fstream>
#include <iostream>
#include <ranges>
#include <regex>

int main(void)
{
	// auto path = std::filesystem::path("ex4.4") / "school.csv";
	// std::ifstream fs(path);
	// fs >> std::noskipws;

	// for (std::string str; std::getline(fs, str);)
	// {
	// 	size_t i = 0;
	// 	auto word = std::ranges::views::split(str, ';');
			// | std::ranges::views::transform([&](std::string str) {
			// 	std::stringstream sstream{};
			// 	switch (i++)
			// 	{
			// 		case 0: sstream << std::left  << std::setw(6);  break;
			// 		case 1: sstream << std::right << std::setw(24); break;
			// 		case 2: sstream << std::left  << std::setw(5);  break;
			// 	}

			// 	sstream << str;
			// 	return sstream.str();
			// });

		// for (auto line : range) std::cout << line;
		// std::cout << std::endl;
	// }

	return 0;
}
