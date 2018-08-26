#pragma once
#include "TypesAliases.h"

class OptimizationStrategy
{
public:
	OptimizationStrategy(Data&& test_runs);
	Data optimize();
	virtual ~OptimizationStrategy() = default;
protected:
	virtual void calculateNewLimit() = 0;
private:
	void prepareData();
	Data mergeData();
	Data test_runs;
};

