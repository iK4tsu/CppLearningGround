#include <iostream>

template<class T>
T fibonacciV1(const T n)
{
	if (!n)          return 0;
	else if (n == 1) return 1;
	else             return fibonacciV1(n - 1) + fibonacciV1(n - 2);
}

template<class T>
T fibonacciV2(T n)
{
	T prev = 0;
	T curr = 1;
	T out;

	for (--n; n; n--)
	{
		out = prev + curr;
		prev = curr;
		curr = out;
	}

	return out;
}

int main(void)
{
	std::cout << fibonacciV1(40) << std::endl;
	std::cout << fibonacciV2(40) << std::endl;

	return 0;
}
