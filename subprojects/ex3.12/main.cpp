#include <iostream>

template<class T>
bool equals(const T a, const T b)
{
	return a == b;
}

int main(void)
{
	std::cout << equals(4, 4) << std::endl;
	std::cout << equals("1", "a") << std::endl;

	return 0;
}
