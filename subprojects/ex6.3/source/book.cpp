#include "../include/book.h"

size_t Book::m_global = 100;

Book::Book(std::string title, Book::LoanType loanType)
	: m_id(m_global++)
	, m_title(std::move(title))
	, m_loanType(loanType)
{}
