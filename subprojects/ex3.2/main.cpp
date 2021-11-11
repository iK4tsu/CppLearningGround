#include <iostream>
#include <cmath>

template<class T>
T max2(const T param1, const T param2)
{
	return (param1 > param2 ? param1 : param2);
}

int main(void)
{
	std::cout << max2(-4,  5) << std::endl;
	std::cout << max2(-3, -2) << std::endl;

	return 0;
}
