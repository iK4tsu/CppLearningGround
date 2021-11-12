#include <iostream>
#include <vector>

#include "student.h"
#include "fellow.h"

int main()
{
	std::vector<Student> students;
	students.push_back(Student("Maria", 9855678, Date(18, 7, 1990), Date(1, 9, 2014)));
	students.push_back(Student("Maria", 9855678, Date(18, 7, 1990)));

	std::vector<Fellow> fellows;
	fellows.push_back(Fellow("Maria", 9855678, Date(18, 7, 1990), Date(1, 9, 2014), 1500.5));
	fellows.push_back(Fellow("Maria", 9855678, Date(18, 7, 1990)));

	Student s;
	std::cout << "Info for a new student:" << std::endl;
	std::cin >> s;
	students.push_back(s);

	Fellow f;
	std::cout << "Info for a new fellow:" << std::endl;
	std::cin >> f;
	fellows.push_back(f);

	for(const auto& x : students) std::cout << x << '\n';
	for(const auto& x : fellows) std::cout << x << '\n';
	std::cout.flush();

	return 0;
}
