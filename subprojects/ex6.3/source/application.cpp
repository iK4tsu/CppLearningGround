#include "../include/application.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

std::optional<size_t> Application::loanBy(size_t userId) const
{
	return library.loanBy(userId);
}

void Application::run()
{
	while (!m_over)
	{
		// refresh the screen
		displayMenu();

		// handle input
		const auto choice = handleInput();

		// execute tasks
		processInput(choice);
	}
}

void Application::displayMenu() const
{
	std::cout
		<< std::setfill('=') << std::right
		<< std::setw(10) << ' ' << '\n'
		<< "Options\n"
		<< std::setw(10) << ' ' << '\n'
		<< std::setfill(' ')
		<< "[1] Enrol student\n"
		<< "[2] Remove student\n"
		<< "[3] Print user list\n"
		<< "[4] Register book\n"
		<< "[5] Print book list\n"
		<< "[6] Loan book\n"
		<< "[7] Return book\n"
		<< "[8] Exit\n"
	<< std::endl;
}

unsigned char Application::handleInput() const
{
	std::cout << "> ";
	unsigned char choice;
	std::cin >> choice;
	std::cin.ignore();
	std::cout << std::endl;
	return choice;
}

void Application::processInput(unsigned char choice)
{
	switch (choice)
	{
		case '1': enrolStudent();  break;
		case '2': removeStudent(); break;
		case '3': printUserList(); break;
		case '4': break;
		case '5': printBookList(); break;
		case '6': break;
		case '7': break;
		case '8': m_over = true;   break;
		default:
			std::cout
				<< "[Error] invalid choice, please insert a number from [1-9]\n"
				<< "[Press ENTER to continue]";
			std::cin.get();
			std::cout << std::endl;
	}
}

void Application::enrolStudent()
{
	std::cout << "nMec: ";
	size_t nMec;
	std::cin >> nMec;

	if (library.users().contains(nMec))
	{
		const User& user = library.users().at(nMec);
		std::cout
			<< "The user of id [" << nMec << "] already exists!\n"
			<< "[" << nMec << "] "
			<< user.name() << " | "
			<< user.course() << '\n'
			<< "Do you wish to overwrite the current data? [yN]\n"
			<< "> ";

		unsigned char choice;
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
			case 'y':
			case 'Y': break;
			default:
				std::cout
					<< "[Action aborted]\n"
					<< "[Press ENTER to continue]";
				std::cin.ignore();
				return;
		}
	}

	std::cout << "Name: ";
	std::string name;
	std::getline(std::cin, name);

	std::cout << "Course: ";
	std::string course;
	std::getline(std::cin, course);

	User user(nMec, std::move(name), std::move(course));
	library.addUser(std::move(user));

	std::cout
		<< "[User added successfuly]\n"
		<< "[Press ENTER to continue]";
	std::cin.ignore();
}

void Application::removeStudent()
{
	std::cout << "nMec: ";
	size_t nMec;
	std::cin >> nMec;
	std::cin.ignore();

	if (!library.users().contains(nMec))
	{
		std::cout
			<< "User [" << nMec << "] does not exist!\n"
			<< "[Action aborted]\n"
			<< "[Press ENTER to continue]";
		std::cin.ignore();
		return;
	}

	const User& user = library.users().at(nMec);
	std::cout
		<< "[" << nMec << "] "
		<< user.name() << " | "
		<< user.course() << '\n'
		<< "Do you want to proceed with the removal of this user?\n"
		<< "This action cannot be undone! [yN]\n"
		<< "> ";

	unsigned char choice;
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
		case 'y':
		case 'Y':
			library.removeUser(nMec);
			std::cout << "[User removed successfuly]\n";
			break;
		default:
			std::cout << "[Action aborted]\n";
	}

	std::cout << "[Press ENTER to continue]";
	std::cin.ignore();
}

void Application::printUserList() const
{
	std::cout
		<< std::setw(8)  << std::left << "nMec"
		<< std::setw(70) << std::left << "name"
		<< std::setw(12) << std::left << "course"
		<< '\n'
		<< std::setfill('#')
		<< std::setw(90) << std::right << ' '
		<< '\n'
		<< std::setfill(' ');

	for (auto& [nMec, user] : users())
	{
		std::cout
			<< std::setw(8)  << std::left << nMec
			<< std::setw(70) << std::left << user.name()
			<< std::setw(12) << std::left << user.course()
			<< '\n';
	}

	std::cout << "\n[Press ENTER to continue]";
	std::cin.ignore();
}

void Application::printBookList() const
{
	std::cout
		<< std::setw(8)  << std::left << "id"
		<< std::setw(100) << std::left << "title"
		<< std::setw(12) << std::left << "loan"
		<< '\n'
		<< std::setfill('#')
		<< std::setw(120) << std::right << ' '
		<< '\n'
		<< std::setfill(' ');

	for (auto& [id, book] : catalog())
	{
		std::cout
			<< std::setw(8)  << std::left << id
			<< std::setw(12) << std::left << book.title()
			<< std::setw(12) << std::left << (library.loanOf(book.id()) ? library.loanOf(book.id()).value().name() : "")
			<< '\n';
	}

	std::cout << "\n[Press ENTER to continue]";
	std::cin.ignore();
}
