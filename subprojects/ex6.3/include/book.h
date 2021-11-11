#pragma once

#include <cstddef>
#include <string>

class Book
{
public:
	enum struct LoanType
	{
		conditional,
		normal,
	};

	Book(std::string, LoanType);

	inline size_t id() const { return m_id; }
	inline std::string_view title() const { return m_title; }
	inline std::string_view loanType() const { return toString(m_loanType); }

private:
	static inline constexpr std::string_view toString(LoanType type)
	{
		switch (type)
		{
			case LoanType::conditional: return "Conditional";
			case LoanType::normal: return "Normal";
		}
	}

	static size_t m_global;
	const size_t m_id;
	const std::string m_title;
	const LoanType m_loanType;
};
