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
	virtual void calculateNewLimit() = 0;
private:
	double mean(const std::vector<double>& times) const;
	double standardDeviation(const std::vector<double>& times) const;
	void threeSdLaw(std::vector<double>& times, double sd);
	void prepareData();
	Data mergeData();
	Data test_runs;
	std::map<uint8_t, std::vector<double>> sorted_runs;
};

