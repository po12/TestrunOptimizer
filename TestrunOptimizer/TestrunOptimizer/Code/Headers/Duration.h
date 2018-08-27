#pragma once
#include <cstdint>
#include <fstream>

struct Duration
{
	uint8_t hours;
	uint8_t minutes;

	operator double() const
	{
		double mins = minutes / 60.0;
		return hours + mins;
	}

	bool operator==(const Duration& rhs) const;
	bool operator!=(const Duration& rhs) const;
	bool operator<(const Duration& rhs) const;
	friend std::istream& operator>>(std::istream&, Duration&);
private:
	unsigned toMinutes() const
	{
		return (hours * 60) + minutes;
	}
	Duration fromMinutes(unsigned minutes) const;
};