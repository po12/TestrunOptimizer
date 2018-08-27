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
	void calculateNewLimit() override;
};

