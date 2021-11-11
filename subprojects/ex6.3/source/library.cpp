#include "../include/library.h"

Library::Library(std::initializer_list<User> users, std::initializer_list<Book> catalog)
	: m_users(users
		| ranges::views::transform([](User user) { return std::make_pair(user.nMec(), std::make_pair(user, std::array<size_t, 3>())); })
		| ranges::to<std::map>()
	)
	, m_catalog(catalog
		| ranges::views::transform([](Book book) -> std::pair<size_t, Book> { return {book.id(), book}; })
		| ranges::to<std::map>()
	)
{}

Library& Library::addBook(Book book)
{
	m_catalog.emplace(book.id(), book);
	return *this;
}

Library& Library::addUser(User user)
{
	m_users.insert_or_assign(user.nMec(), std::make_pair(std::move(user), std::array<bookId, 3>()));
	return *this;
}

Library& Library::removeBook(size_t id)
{
	m_catalog.erase(id);
	return *this;
}

Library& Library::removeUser(size_t nMec)
{
	m_users.erase(nMec);
	return *this;
}

std::optional<size_t> Library::loanBy(size_t userId) const
{
	return m_users.contains(userId)
		? std::make_optional(m_users.at(userId).second.size())
		: std::nullopt;
}

std::optional<const User> Library::loanOf(size_t bookId) const
{
	return m_loans.contains(bookId)
		? std::make_optional(m_users.at(m_loans.at(bookId)).first)
		: std::nullopt;
}
