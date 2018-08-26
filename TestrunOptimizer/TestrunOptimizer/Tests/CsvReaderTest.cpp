#define _HAS_TR1_NAMESPACE 1
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include <gtest/gtest.h>

#include "CsvReader.h"
#include "TypesAliases.h"
#include <filesystem>

class CsvReaderTestSuite : public ::testing::Test
{
public:
	CsvReader sut;
	void checkSingleEntry(const TestInfo& entry, const TestInfo& expected) const
	{
		ASSERT_EQ(std::get<0>(entry), std::get<0>(expected));
		ASSERT_EQ(std::get<1>(entry), std::get<1>(expected));
	}
};

TEST_F(CsvReaderTestSuite, ThrowsExceptionForNotExistingFile)
{
	ASSERT_THROW(sut.read("NotExistingFile.csv"), std::runtime_error);
}

TEST_F(CsvReaderTestSuite, CanReadSingleLine)
{
	auto data = sut.read("../input/simple.csv");
	ASSERT_EQ(data.size(), 1);

	checkSingleEntry(data[0], { 8 , Duration{1,31} });
}

TEST_F(CsvReaderTestSuite, CanReadFileWithMultipleLines)
{
	auto data = sut.read("../input/multiline.csv");
	ASSERT_EQ(data.size(), 5);

	checkSingleEntry(data[0], { 3 , Duration{2,2} });
	checkSingleEntry(data[1], { 4 , Duration{0,5} });
	checkSingleEntry(data[2], { 8 , Duration{2,34} });
	checkSingleEntry(data[3], { 4 , Duration{2,35} });
	checkSingleEntry(data[4], { 4 , Duration{2,03} });
}