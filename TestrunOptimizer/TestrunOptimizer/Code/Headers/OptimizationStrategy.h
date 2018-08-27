#pragma once
#include "TypesAliases.h"
#include <map>

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
	virtual CalculationResult calculateNewLimit() = 0;
	SortedRuns sorted_runs;

private:
	double mean(const std::vector<double>& times);
	double standardDeviation(const std::vector<double>& times);
	void threeSdLaw(std::vector<double>& times, double sd);
	void prepareData();
	Data mergeData(const CalculationResult& calculation_results);
	Data test_runs;
	
};

