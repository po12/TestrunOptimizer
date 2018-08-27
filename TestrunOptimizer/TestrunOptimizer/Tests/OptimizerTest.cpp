#define _HAS_TR1_NAMESPACE 1
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include <gtest/gtest.h>
#include <filesystem>
#include "Optimizer.h"
#include "OptimizationStrategy.h"
#include "CsvReader.h"

class OptimizationTestSuite : public ::testing::Test
{
public:
	Optimizer sut;
	CsvReader reader;
};

TEST_F(OptimizationTestSuite, CanConstructOptimizer)
{
	sut = reader.read("../input/normal_15.csv");

	sut.setStrategy(StrategyType::MEDIAN);
	sut.optimize();
}