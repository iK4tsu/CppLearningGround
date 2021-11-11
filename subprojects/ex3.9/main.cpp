#include <iostream>

double pow(double n, int p = 2)
{
	if (!p) return 1;

	for (--p; p; p--)
		n *= n;

	return n;
}

int main(void)
{
	return 0;
}
