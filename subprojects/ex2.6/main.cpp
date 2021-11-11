#include <iostream>

enum OP
{
	ADD = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/',
};

struct Frac
{
	float add(const Frac& frac)
	{
		return (a * frac.b + b * frac.a) / (b * frac.b);
	}

	float sub(const Frac& frac)
	{
		return (a * frac.b - b * frac.a) / (b * frac.b);
	}

	float mul(const Frac& frac)
	{
		return (a * frac.a) / (b * frac.b);
	}

	float div(const Frac& frac)
	{
		return (a * frac.b) / (b * frac.a);
	}

	float a;
	float b;
};

int main()
{
	auto fraction = []() {
		Frac frac;
		std::scanf("%f/%f", &frac.a, &frac.b);
		return frac;
	};

	std::cout << "Fraction 1 > ";
	Frac frac1 = fraction();

	std::cout << "Operator > ";
	OP op = []() {
		unsigned char c;
		std::cin >> c;
		return static_cast<OP>(c);
	} ();

	std::cout << "Fraction 2 > ";
	Frac frac2 = fraction();

	float result;
	switch (op)
	{
		case ADD: result = frac1.add(frac2); break;
		case SUB: result = frac1.sub(frac2); break;
		case MUL: result = frac1.mul(frac2); break;
		case DIV: result = frac1.div(frac2); break;
	}

	std::cout << "Result: " << result << std::endl;

	return 0;
}
