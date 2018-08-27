#pragma once
#include "TypesAliases.h"

enum class StrategyType
{
	MEDIAN = 0
};

class OptimizationStrategy
{
public:
	OptimizationStrategy(Data& test_runs);
	Data optimize();
	virtual ~OptimizationStrategy() = default;
protected:
	virtual void calculateNewLimit() = 0;
private:
	void prepareData();
	Data mergeData();
	Data test_runs;
};

