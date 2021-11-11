#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	size_t len;
	std::cout << "Length > ";
	std::cin >> len;

	std::vector<int> values(len);
	for (; len--;)
	{
		int value;
		std::cout << "Enter a value > ";
		std::cin >> value;
		values.push_back(value);
	}

	std::cout
		<< "Max: "
		<< std::ranges::max(values)
		<< std::endl;

	return 0;
}
