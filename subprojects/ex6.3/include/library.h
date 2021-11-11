#pragma once

#include <initializer_list>
#include <map>
#include <optional>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/transform.hpp>
#include "book.h"
#include "user.h"

class Library
{
public:
	Library() = default;
	Library(std::initializer_list<User>, std::initializer_list<Book>);

	inline const std::map<size_t, User> users() const
	{
		return m_users
			| ranges::views::transform([](auto& pair) { return std::make_pair(pair.first, pair.second.first); })
			| ranges::to<std::map>();
	}

	inline const std::map<size_t, Book>& catalog() const { return m_catalog; }

	/*
	@brief Adds a Book to the catalog.

	If a Book with the same id already exists in the catalog, it'll be replaced
	by the new one.

	@param book The Book to add.
	@returns A reference to the updated library.
	*/
	Library& addBook(Book book);

	/*
	@brief Adds a User to the user list.

	If a User with the same university id already exists in the catalog, it'll
	be replaced by the new one.

	@param book The User to add.
	@returns A reference to the updated library.
	*/
	Library& addUser(User);

	/*
	@brief Removes a Book from the catalog if exists.
	@param bookId A valid Book id.
	@returns A reference to the updated library.
	*/
	Library& removeBook(size_t bookId);

	/*
	@brief Removes a User from the user list if exists.
	@param nMec A valid User university id.
	@returns A reference to the updated library.
	*/
	Library& removeUser(size_t nMec);

	/*
	@brief Loans an available Book to a User.
	@param userId A valid User university id.
	@param bookId A valid Book id.
	@returns A reference to the updated library.
	*/
	Library& loanBook(size_t userId, size_t bookId);

	/*
	@brief Returns a loaned Book from a User.
	@param userId A valid User university id.
	@param bookId A valid Book id.
	@returns A reference to the updated library.
	*/
	Library& returnBook(size_t userId, size_t bookId);

	std::optional<size_t> loanBy(size_t userId) const;
	std::optional<const User> loanOf(size_t bookId) const;

private:
	typedef size_t bookId;
	typedef size_t userId;

	std::map<userId, std::pair<User, std::array<bookId, 3>>> m_users{};
	std::map<bookId, Book> m_catalog{};
	std::map<bookId, userId> m_loans{};
};
