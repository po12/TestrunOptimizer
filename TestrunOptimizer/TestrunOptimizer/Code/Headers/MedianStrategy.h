#pragma once
#include "OptimizationStrategy.h"
#include "TypesAliases.h"

class MedianStrategy : public OptimizationStrategy
{
public:
	MedianStrategy(Data& test_runs);
	MedianStrategy() = default;
	~MedianStrategy() = default;
protected:
	CalculationResult calculateNewLimit() override;
private:
	double median(const std::vector<double>& times) const;
};

