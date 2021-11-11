#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::string keyword;
	std::cout << "Keyword > ";
	std::cin >> keyword;

	std::string text;
	for (
		std::string str;
		(std::getline(std::cin, str, '$'), str != "\nEnd" && str != "End");
		text.append(str)
	);

	std::regex rwords("[\\w]+");
	auto begin = std::sregex_iterator(text.begin(), text.end(), rwords);
	auto end = std::sregex_iterator();
	auto words = std::distance(begin, end);
	std::cout << "Word count: " << words << std::endl;

	std::regex rkeywords("(\\$|\\b)"+keyword+"(\\s|\\b)");
	begin = std::sregex_iterator(text.begin(), text.end(), rkeywords);
	auto keywords = std::distance(begin, end);
	std::cout << "Keyword cout: " << keywords << std::endl;

	return 0;
}
