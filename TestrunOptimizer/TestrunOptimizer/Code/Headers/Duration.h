#pragma once
#include <cstdint>
#include <fstream>

struct Duration
{
	uint8_t hours;
	uint8_t minutes;

	operator double() const;
	Duration(uint8_t hours, uint8_t minutes) noexcept;
	Duration(double time) noexcept;

	Duration() noexcept = default;
	Duration(const Duration&) noexcept = default;
	Duration(Duration&&) noexcept = default;
	Duration& operator=(const Duration&) noexcept = default;
	Duration& operator=(Duration&&) noexcept = default;
	~Duration() noexcept = default;

	bool operator==(const Duration& rhs) const;
	bool operator!=(const Duration& rhs) const;
	bool operator<(const Duration& rhs) const;
	friend std::istream& operator>>(std::istream&, Duration&);
private:
	unsigned toMinutes() const
	{
		return (hours * 60) + minutes;
	}
};