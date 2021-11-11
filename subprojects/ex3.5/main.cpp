#include <iostream>

unsigned int digitsOf(const unsigned int n)
{
	if (n / 10) return 1 + digitsOf(n / 10);
	else        return 1;
}

int main(void)
{
	std::cout << digitsOf(12304) << std::endl;

	return 0;
}
