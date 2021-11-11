#include <iostream>

void countdown(const unsigned int n)
{
	std::cout << n << std::endl;
	if (n) countdown(n - 1);
}

int main(void)
{
	countdown(5);

	return 0;
}
