#include <assert.h>
#include <fstream>
#include <iostream>

int main(void)
{
	std::string path("ex4.1/");
	std::string filename;
	std::cout << "File 1 > ";
	std::cin >> filename;

	if (!std::ifstream(path + filename).good()) std::ofstream(path + filename);
	std::ifstream fs1(path + filename);
	assert(fs1.good());

	std::cout << "File 2 > ";
	std::cin >> filename;

	std::ofstream fs2(path + filename);

	while (!fs1.eof())
	{
		std::string str;
		fs1 >> str;
		fs2 << str;
	}

	fs1.close();
	fs2.close();

	return 0;
}
