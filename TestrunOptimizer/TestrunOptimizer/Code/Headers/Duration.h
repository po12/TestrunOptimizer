#pragma once
#include <cstdint>
#include <fstream>

class MinutesOverflowException : std::runtime_error
{
public:
	MinutesOverflowException(const std::string& message) throw();
	virtual char const* what() const throw();
};

struct Duration
{
	uint8_t hours;
	uint8_t minutes;

	bool operator==(const Duration& rhs) const;
	bool operator!=(const Duration& rhs) const;
	friend std::istream& operator>>(std::istream&, Duration&);
};