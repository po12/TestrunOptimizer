#include "Duration.h"
#include <sstream>
#include <array>

bool Duration::operator==(const Duration& rhs) const
{
	return hours == rhs.hours && minutes == rhs.minutes;
}

std::istream& operator>>(std::istream& is, Duration& dur)
{
	std::string str;
	std::getline(is, str, ':');
	dur.hours = std::stoi(str);
	is >> str;
	dur.minutes = std::stoi(str);
	return is;
}