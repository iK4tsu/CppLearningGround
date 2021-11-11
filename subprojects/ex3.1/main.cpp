#include <iostream>
#include <cmath>

std::string bmi(const float weight, const float height)
{
	const float bmi = weight/(std::pow(2, height));
	if (bmi < 18.5f)   return "Underweight";
	else if (bmi < 25) return "Normal";
	else if (bmi < 30) return "Overweight";
	else               return "Obese";
}

int main(void)
{
	float height;
	float weight;

	std::cout << "Weight > ";
	std::cin >> weight;

	std::cout << "Height > ";
	std::cin >> height;

	std::cout << "BMI [" << bmi(weight, height) << "]" << std::endl;

	return 0;
}
