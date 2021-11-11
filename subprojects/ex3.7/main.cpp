#include <bitset>
#include <iostream>

template<class T>
T gdcV1(const T a, const T b)
{
	if (b) return gdcV1(b, a%b);
	else   return a;
}

template<class T>
T gdcV2(T a, T b)
{
	while (b)
	{
		T tmp = b;
		b = a%b;
		a = tmp;
	}

	return a;
}

int main(void)
{
	std::cout << gdcV1(50, 70) << std::endl;
	std::cout << gdcV2(50, 70) << std::endl;

	return 0;
}
