#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>

int main(void)
{
	auto path = std::filesystem::path("ex4.2") / "nums";

	auto readApply = [](std::filesystem::path path, double res, std::function<double (double, double)> fun) -> double
	{
		std::ifstream file(path);
		if (!file.good())
		{
			std::cerr << "File does not exist" << std::endl;
			exit(1);
		}

		while (!file.eof())
		{
			double d;
			file >> d;
			if (!file.fail()) res = fun(res, d);
		}

		return res;
	};

	std::cout << readApply(path, 0, [](double a, double b) { return a + b; }) << std::endl;
	std::cout << readApply(path, std::numeric_limits<double>::min(), [](double a, double b) { return a > b ? a : b; }) << std::endl;
	std::cout << readApply(path, std::numeric_limits<double>::max(), [](double a, double b) { return a < b ? a : b; }) << std::endl;

	return 0;
}
