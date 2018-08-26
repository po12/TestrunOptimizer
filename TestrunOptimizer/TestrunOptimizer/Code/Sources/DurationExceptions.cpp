#include "DurationExceptions.h"

WrongDurationFormatException::WrongDurationFormatException(char const* const message) throw() : std::runtime_error(message)
{}

char const* WrongDurationFormatException::what() const throw()
{
	return exception::what();
}

MinutesOverflowException::MinutesOverflowException(char const* const message) throw() : WrongDurationFormatException(message)
{}

char const* MinutesOverflowException::what() const throw()
{
	return exception::what();
}
