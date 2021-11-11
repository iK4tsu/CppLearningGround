#include <iostream>

template<class T>
T max2(const T param1, const T param2)
{
	return (param1 > param2 ? param1 : param2);
}

template<class T>
T max3(const T param1, const T param2, const T param3)
{
	return max2(max2(param1, param2), param3);
}

int main(void)
{
	std::cout << max3(-4,  5, -2) << std::endl;
	std::cout << max3(-3, -2, 10) << std::endl;

	return 0;
}
