#include <iostream>

#include "mtime.h"

int main(void)
{
	Time time1(12, 10, 30);
	Time time2(11, 50, 35);
	Time time3 = time1 - time2;

	std::cout
		<< time1 << " - "
		<< time2 << " = "
		<< time3
	<< std::endl;

	return 0;
}
