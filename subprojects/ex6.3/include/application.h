#pragma once

#include <initializer_list>
#include <set>
#include "library.h"
#include "book.h"
#include "user.h"

class Application
{
public:
	friend Library;

	static Application& init()
	{
		static Application application{
			{
				User(65473, "Alberto", "Mathematics"),
				User(63295, "Vitor", "Mathematics"),
				User(33256, "Jorge", "Physics"),
				User(97064, "Roberto", "philosophy"),
			},
			{
				Book("The adventures of learning a new programming language", Book::LoanType::normal),
				Book("Are libraries still relevant?", Book::LoanType::normal),
				Book("The abc's of imagination", Book::LoanType::normal),
				Book("Read, read, read", Book::LoanType::normal),
				Book("Adaptation or extintion", Book::LoanType::normal),
			}
		};

		return application;
	}

	Application() = delete;
	Application(const Application&) = delete;
	void operator=(const Application&) = delete;

	inline const std::map<size_t, User> users() const { return library.users(); }
	inline const std::map<size_t, Book> catalog() const { return library.catalog(); }
	inline bool over() const { return m_over; }

	std::optional<size_t> loanBy(size_t) const;

	void run();

private:
	Application(std::initializer_list<User> users, std::initializer_list<Book> books) : library(users, books) {}

	void displayMenu() const;
	unsigned char handleInput() const;
	void processInput(unsigned char);

	// menu
	void enrolStudent();
	void removeStudent();
	void printUserList() const;
	void printBookList() const;

	bool m_over{false};
	Library library{};
};
