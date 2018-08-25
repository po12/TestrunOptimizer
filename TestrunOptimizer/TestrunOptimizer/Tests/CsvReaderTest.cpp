#define _HAS_TR1_NAMESPACE 1
#include <gtest/gtest.h>
#include "CsvReader.h"

class CsvReaderTestSuite : public ::testing::Test
{
	CsvReader sut;
};

TEST_F(CsvReaderTestSuite, CanConstructObject)
{

}