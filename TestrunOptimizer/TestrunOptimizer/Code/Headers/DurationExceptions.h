#pragma once
#include <stdexcept>

class WrongDurationFormatException : public std::runtime_error
{
public:
	WrongDurationFormatException(char const* const message) throw();
	virtual char const* what() const throw();
};

class MinutesOverflowException : public WrongDurationFormatException
{
public:
	MinutesOverflowException(char const* const message) throw();
	virtual char const* what() const throw();
};
