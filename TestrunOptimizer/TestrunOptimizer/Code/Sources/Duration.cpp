#include <sstream>
#include <array>
#include "DurationExceptions.h"
#include "Duration.h"

bool Duration::operator<(const Duration& rhs) const
{
	return toMinutes() < rhs.toMinutes();
}

bool Duration::operator==(const Duration& rhs) const
{
	return hours == rhs.hours && minutes == rhs.minutes;
}

bool Duration::operator!=(const Duration& rhs) const
{
	return !(*this == rhs);
}
Duration Duration::fromMinutes(unsigned minutes) const
{
	Duration dur;
	dur.minutes = minutes % 60;
	dur.hours = (minutes - dur.minutes) / 60;
	return dur;
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
	else if (dur.minutes > 60)
	{
		const auto wrong_minutes = dur.minutes;
		dur = Duration{};
		std::string msg =  std::to_string(wrong_minutes) + " is not valid value for minutes in hour";
		throw MinutesOverflowException(msg.c_str());
	}

	return is;
}