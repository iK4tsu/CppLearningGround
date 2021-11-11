#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <ranges>
#include <sstream>
#include "point.h"

#define FORMAT(w, text_l, text_r) std::setw(w) << text_l << std::setw(w) << text_r << std::endl
#define FORMAT4(w, t1, t2, t3, t4) std::setw(w) << t1 << std::setw(w) << t2 << std::setw(w) << t3 << std::setw(w) << t4 << std::endl

int main()
{
	// ex1
	std::cout << std::setfill(' ') << std::right
		<< FORMAT(8, "1990", "135")
		<< FORMAT(8, "1991", "1")
		<< FORMAT(8, "1992", "1335")
		<< FORMAT(8, "1993", "1359")
	<< std::endl;

	// ex2
	const int i = 10;
	int j = i * 2;
	std::cout
		<< i << std::endl
		<< j << std::endl;
		j--;
	std::cout
		<< j << std::endl
	<< std::endl;

	// ex3
	int option;
	float temperature;
	std::cout
		<< "[1] Fahrenheit to Celsius" << std::endl
		<< "[2] Celsius to Fahrenheit" << std::endl
		<< "Option > ";
	std::cin >> option;
	std::cout << "Temperature > ";
	std::cin >> temperature;
	std::cout
		<< "In "
		<< (option == 1 ? "Celsius" : "Fahrenheit")
		<< " thats: "
		<< (option == 1 ? (temperature - 32) / 1.8 : (temperature * 1.8 + 32))
	<< std::endl;

	// ex4
	float first;
	float second;
	float a;
	float b;
	char dummy;

	std::cout << "Fraction 1 > ";
	std::cin >> first >> dummy >> second;
	a = first/second;

	std::cout << "Fraction 2 > ";
	std::cin >> first >> dummy >> second;
	b = first/second;

	std::cout
		<< std::endl
		<< "Answer: " << a + b
		<< std::endl
	<< std::endl;

	// ex5
	std::cout << std::setfill(' ') << std::left
		<< FORMAT4(15, "Last_name", "Last_name", "Town", "Country")
		<< std::setfill('-') << std::setw(15*4) << "" << std::endl << std::setfill(' ')
		<< FORMAT4(15, "Silva", "Joao", "Aveiro", "Portugal")
		<< FORMAT4(15, "Almeida", "Maria", "Madrid", "Spain")
		<< FORMAT4(15, "Santos", "Miguel", "Moscow", "Russia")
	<< std::endl;

	// ex6
	print({ 2, 3 });
	std::cout << std::endl << std::endl;

	// ex7
	Point2D point;
	Point2D furthest = {0, 0};
	int number = 0;
	double sum = 0.0;

	while ((point = scanPoint()), point.x || point.y)
	{
		number++;
		sum += distanceOf(point);
		if (distanceOf(point) > distanceOf(furthest))
			furthest = point;
	}

	std::cout
		<< "Number of points entered: " << number << std::endl
		<< "Sum of distances to the origin: " << sum << std::endl
		<< "Furthest point from the origin: ";
	print(furthest);
	std::cout << std::endl << std::endl;

	// ex8
	int value;
	std::cout << "Enter a number: ";
	std::cin >> value;

	auto result = [value]() {
		int index{1};

		return std::views::iota(1)
			| std::views::transform([value, index](int n) mutable {
				std::ostringstream stream;

				stream << std::left
					<< std::setw(4)
					<< n * value
					<< (index++ % 10 == 0 ? '\n' : ' ');

				return stream.str();
		});
	};

	for (auto v : result() | std::views::take(10*3)) std::cout << v;

	std::cout << std::endl;

	// ex9
	int xnumber;
	std::cout << "Enter a number > ";
	std::cin >> xnumber;

	auto range = std::views::iota(1)
		| std::views::filter([](int i) { return i&1; })
		| std::views::transform([xnumber](int i) {
			std::ostringstream stream;

			stream << std::right
				<< std::setw(xnumber + i / 2)
				<< std::string(i, 'x');

			return stream.str();
		})
		| std::views::take(xnumber);

	for (auto x : range) std::cout << x << '\n';

	std::cout << std::endl;

	return 0;
}
