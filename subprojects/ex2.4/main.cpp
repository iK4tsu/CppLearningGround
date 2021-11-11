#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

int count_alpha(const std::string& str)
{
	std::regex regex("[a-zA-Z]");
	auto begin = std::regex_iterator(str.begin(), str.end(), regex);
	auto end = std::sregex_iterator();
	return std::distance(begin, end);
}

int count_lowers(const std::string& str)
{
	std::regex regex("[a-z]");
	auto begin = std::regex_iterator(str.begin(), str.end(), regex);
	auto end = std::sregex_iterator();
	return std::distance(begin, end);
}

int count_uppers(const std::string& str)
{
	std::regex regex("[A-Z]");
	auto begin = std::regex_iterator(str.begin(), str.end(), regex);
	auto end = std::sregex_iterator();
	return std::distance(begin, end);
}

void equals_or_greater(const std::string& str1, const std::string& str2)
{
	std::cout << str1.compare(str2) << std::endl;
}

std::string toLower(const std::string& str)
{
	std::string ret;
	ret.reserve(str.length());

	for (char ch : str)
		ret.push_back(ch >= 'A' && ch <= 'Z'
			? ch + 'a' - 'A'
			: ch
		);

	return ret;
}

std::string replace(const std::string& str)
{
	std::regex regex("  +");
	return std::regex_replace(str, regex, " ");
}

std::string capitalize(const std::string& str)
{
	std::string ret;
	ret.reserve(str.length());

	std::regex regex("[^\\s]+|[\\s]+");
	auto begin = std::regex_iterator(str.begin(), str.end(), regex);
	for (std::sregex_iterator i = begin; i != std::sregex_iterator(); i++)
	{
		std::string match = (*i).str();
		ret.append(match[0] >= 'a' && match[0] <= 'z'
			? (match[0] -= 'a' - 'A', match)
			: match
		);
	}

	return ret;
}

bool isPalindrome(const std::string& str)
{
	return std::equal(str.begin(), str.begin() + str.length() / 2, str.rbegin());
}

int main()
{
	std::cout << count_alpha("tfD2321$cc@4#") << std::endl;
	std::cout << count_lowers("tfD2321$cc@4#") << std::endl;
	std::cout << count_uppers("tfD2321$cc@4#") << std::endl;
	equals_or_greater("a", "b");
	std::cout << toLower("all TO loWeR 43") << std::endl;
	std::cout << replace("No   multiple  spaces     here") << std::endl;
	std::cout << capitalize("capitalize This sentence  #notthis, this$yes") << std::endl;
	std::cout << isPalindrome("aabaa") << std::endl;

	return 0;
}
