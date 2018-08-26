#define _HAS_TR1_NAMESPACE 1
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include <gtest/gtest.h>

#include "CsvReader.h"
#include <filesystem>

class CsvReaderTestSuite : public ::testing::Test
{
public:
	CsvReader sut;
};

TEST_F(CsvReaderTestSuite, ThrowsExceptionForNotExistingFile)
{
	ASSERT_THROW(sut.read("NotExistingFile.csv"), std::runtime_error);
}

TEST_F(CsvReaderTestSuite, CanReadSingleLine)
{
	auto data = sut.read("../input/simple.csv");
	ASSERT_EQ(data.size(), 1);

	const auto test_id = std::get<0>(data[0]);
	ASSERT_EQ(test_id, 8);

	const auto duration = std::get<1>(data[0]);
	const auto expected = Duration{ 1, 31 };
	EXPECT_EQ(duration, expected);
}
