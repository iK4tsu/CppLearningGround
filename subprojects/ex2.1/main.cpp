#include <functional>
#include <iostream>
#include <numeric>
#include <ranges>

int main()
{
	int value;
	while ((value = []() {
		int value;
		std::cout << "Enter a number > ";
		std::cin >> value;
		return value;
	} ()) > 0)
	{
		auto iota = std::views::iota(1, value + 1);
		std::cout
			<< std::accumulate(iota.begin(), iota.end(), 1, std::multiplies<int>())
		<< std::endl;
	}

	return 0;
}
