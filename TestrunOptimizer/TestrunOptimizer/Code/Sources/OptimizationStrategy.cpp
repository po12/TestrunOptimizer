#include "OptimizationStrategy.h"

OptimizationStrategy::OptimizationStrategy(Data&& test_runs) : test_runs(std::move(test_runs))
{
}

void OptimizationStrategy::prepareData()
{

}

Data OptimizationStrategy::mergeData()
{
	return {};
}

Data OptimizationStrategy::optimize()
{
	prepareData();
	calculateNewLimit();
	return mergeData();
}