#include <iostream>

#include "circle.h"
#include "point.h"
#include "rectangle.h"
#include "square.h"

int main(void)
{
	Circle circle({ 0, 0 }, 4);
	Square Square({ 0, 0 }, 4);
	Rectangle rectangle({ 0, 0 }, 2, 3);

	std::cout
		<< "[Circle area]: "         << circle.area()         << '\n'
		<< "[Square area]: "         << Square.area()         << '\n'
		<< "[Rectangle area]: "      << rectangle.area()      << '\n'
		<< '\n'
		<< "[Circle perimeter]: "    << circle.perimeter()    << '\n'
		<< "[Square perimeter]: "    << Square.perimeter()    << '\n'
		<< "[Rectangle perimeter]: " << rectangle.perimeter() << '\n'
		<< '\n'
		<< "[Circle intersects]: "   << (circle.intersects({{ 0, 4 }, 1 }) ? "yes" : "no")
	<< std::endl;

	return 0;
}
