#define _HAS_TR1_NAMESPACE 1
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING

#include <gtest/gtest.h>
#include <filesystem>
#include <tuple>
#include "Optimizer.h"
#include "Duration.h"
#include "OptimizationStrategy.h"
#include "CsvReader.h"

class OptimizationTestSuite : public ::testing::Test
{
public:
	Optimizer sut;
	CsvReader reader;
	void setupMedianTest(const char* path)
	{
		sut = reader.read(path);
		sut.setStrategy(StrategyType::MEDIAN);
	}

	void verifyOptimization(const Data& expected)
	{
		ASSERT_EQ(sut.optimize(), expected);
	}
};

TEST_F(OptimizationTestSuite, OptimizerTestForOneTestWithNormalDistribution)
{
	setupMedianTest("../input/normal_15.csv");
	verifyOptimization(Data{ {1, {0, 53}} });
}

TEST_F(OptimizationTestSuite, OptimizerTestForMultipleTestsWithNormalDistribution)
{
	setupMedianTest("../input/multi_normal_15.csv");
	verifyOptimization(Data{ {1, {0, 59}}, {2, {0, 37}}, {3, {1, 29}} });
}

TEST_F(OptimizationTestSuite, OptimizerTestForOneTestWithBetaDistribution)
{
	setupMedianTest("../input/beta_15.csv");
	verifyOptimization(Data{ {1, {0, 47}} });
}

TEST_F(OptimizationTestSuite, OptimizerTestForMultipleTestsWithBetaDistribution)
{
	setupMedianTest("../input/multi_beta_15.csv");
	verifyOptimization(Data{ {1, {0, 40}}, {2, {0, 40}}, {3, {0, 37}} });
}

TEST_F(OptimizationTestSuite, OptimizerTestForOneTestWithGammaDistribution)
{
	setupMedianTest("../input/gamma_15.csv");
	verifyOptimization(Data{ {1, {0, 26}} });
}

TEST_F(OptimizationTestSuite, OptimizerTestForMultipleTestsWithGammaDistribution)
{
	setupMedianTest("../input/multi_gamma_15.csv");
	verifyOptimization(Data{ {1, {0, 49}}, {2, {0, 44}}, {3, {0, 43}} });
}

TEST_F(OptimizationTestSuite, OptimizerTestForOneTestWithUniformDistribution)
{
	setupMedianTest("../input/uniform_15.csv");
	verifyOptimization(Data{ {1, {0, 41}} });
}

TEST_F(OptimizationTestSuite, OptimizerTestForMultipleTestsWithUniformDistribution)
{
	setupMedianTest("../input/multi_uniform_15.csv");
	verifyOptimization(Data{ {1, {1, 8}}, {2, {0, 56}}, {3, {1, 3}} });
}