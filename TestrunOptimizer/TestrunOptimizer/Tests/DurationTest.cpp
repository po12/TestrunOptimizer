#define _HAS_TR1_NAMESPACE 1
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include <gtest/gtest.h>
#include "Duration.h"
#include "DurationExceptions.h"

class DurationTestSuite : public ::testing::Test
{
public:
	Duration sut;
};

TEST_F(DurationTestSuite, DurationEqualOperatorTest)
{
	Duration left{ 1, 0 };
	Duration right{ 1, 0 };
	ASSERT_EQ(left, right);
	right.minutes++;
	ASSERT_NE(left, right);
}

TEST_F(DurationTestSuite, ReadDurationFromIstreamWithProperData)
{
	std::string proper_data{ "1:1" };
	std::istringstream iss(proper_data);
	Duration dur;
	iss >> dur;
	ASSERT_EQ(dur.hours, 1);
	ASSERT_EQ(dur.minutes, 1);
}

TEST_F(DurationTestSuite, ReadDurationFromIstreamWithWrongData)
{
	std::string wrong_data{ "1:61" };
	std::istringstream iss(wrong_data);
	Duration dur;
	ASSERT_THROW(iss >> dur, MinutesOverflowException);
}

TEST_F(DurationTestSuite, ReadDurationFromIstreamShouldIncrementHourIfMinutesAreEqualTo60)
{
	std::string sixty_minutes_data{ "1:60" };
	std::istringstream iss(sixty_minutes_data);
	Duration dur;
	iss >> dur;
	
	Duration expected = { 2, 0 };
	ASSERT_EQ(dur, expected);
}