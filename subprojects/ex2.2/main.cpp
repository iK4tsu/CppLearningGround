#include <iostream>

long hms_to_secs(int h, int m, int s)
{
	return long(h * 60 * 60 + m * 60 + s);
}

int main()
{
	while (true)
	{
		int h;
		int m;
		int s;
		std::scanf("%d:%d:%d:", &h, &m, &s);
		std::cout << hms_to_secs(h, m, s) << std::endl;
	}

	return 0;
}
