#include "Duration.h"
#include <sstream>
#include <array>

MinutesOverflowException::MinutesOverflowException(const std::string& message) throw() : std::runtime_error(message.c_str())
{}

char const* MinutesOverflowException::what() const throw()
{
	return exception::what();
}

bool Duration::operator==(const Duration& rhs) const
{
	return hours == rhs.hours && minutes == rhs.minutes;
}

bool Duration::operator!=(const Duration& rhs) const
{
	return !(*this == rhs);
}

std::istream& operator>>(std::istream& is, Duration& dur)
{
	std::string str;
	std::getline(is, str, ':');
	dur.hours = std::stoi(str);
	is >> str;
	dur.minutes = std::stoi(str);
	if (dur.minutes == 60)
	{
		dur.hours++;
		dur.minutes = 0;
	}
	else if (dur.minutes > 59)
	{
		const auto wrong_minutes = dur.minutes;
		dur = Duration{};
		std::ostringstream msg;
		msg << wrong_minutes << " is not valid value for minutes in hour";
		throw MinutesOverflowException(msg.str());
	}

	return is;
}