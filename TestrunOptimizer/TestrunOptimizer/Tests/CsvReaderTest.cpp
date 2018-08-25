#define _HAS_TR1_NAMESPACE 1
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