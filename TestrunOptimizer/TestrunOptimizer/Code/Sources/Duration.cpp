#include <sstream>
#include <array>
#include "DurationExceptions.h"
#include "Duration.h"

Duration::Duration(double time) noexcept
{
	hours = uint8_t(time);
	minutes = uint8_t(time*60 - hours*60);
}

Duration::Duration(uint8_t hours, uint8_t minutes) noexcept : hours(hours), minutes(minutes)
{}

Duration::operator double() const
{
	double mins = minutes / 60.0;
	return hours + mins;
}

bool Duration::operator<(const Duration& rhs) const
{
	return toMinutes() < rhs.toMinutes();
}

bool Duration::operator==(const Duration& rhs) const
{
	return toMinutes() == rhs.toMinutes();
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
	else if (dur.minutes > 60)
	{
		const auto wrong_minutes = dur.minutes;
		dur = Duration{};
		std::string msg =  std::to_string(wrong_minutes) + " is not valid value for minutes in hour";
		throw MinutesOverflowException(msg.c_str());
	}

	return is;
}