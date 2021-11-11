#include <iostream>

double pow(double n, int p = 2)
{
	if (!p) return 1;

	for (--p; p; p--)
		n *= n;

	return n;
}

char pow(char n, int p = 2)
{
	if (!p) return 1;

	for (--p; p; p--)
		n *= n;

	return n;
}

short pow(short n, int p = 2)
{
	if (!p) return 1;

	for (--p; p; p--)
		n *= n;

	return n;
}

int pow(int n, int p = 2)
{
	if (!p) return 1;

	for (--p; p; p--)
		n *= n;

	return n;
}

long pow(long n, int p = 2)
{
	if (!p) return 1;

	for (--p; p; p--)
		n *= n;

	return n;
}

float pow(float n, int p = 2)
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
