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

TEST_F(DurationTestSuite, ConvertsProperlyFromDouble)
{
	Duration dur{ 1.0 };
	Duration expected{ 1,0 };

	ASSERT_EQ(dur, expected);
	
	dur = { 0.5 };
	expected = { 0,30 };
	ASSERT_EQ(dur, expected);

	dur = { 1.5 };
	expected = { 1,30 };
	ASSERT_EQ(dur, expected);

	dur = { 10/60.0 };
	expected = { 0,10 };
	ASSERT_EQ(dur, expected);
}

TEST_F(DurationTestSuite, LessOperatorWorksProperly)
{
	Duration lower{ 0, 30 };
	Duration higher{ 0, 45 };
	ASSERT_TRUE(lower < higher);

	higher = { 1, 0 };
	ASSERT_TRUE(lower < higher);
}