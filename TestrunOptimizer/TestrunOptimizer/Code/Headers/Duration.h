#pragma once
#include <cstdint>
#include <fstream>

struct Duration
{
	uint8_t hours;
	uint8_t minutes;

	bool operator==(const Duration& rhs) const;
	bool operator!=(const Duration& rhs) const;
	friend std::istream& operator>>(std::istream&, Duration&);
};