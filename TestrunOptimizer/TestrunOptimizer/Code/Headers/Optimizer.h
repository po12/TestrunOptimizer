#pragma once
#include <memory>
#include "TypesAliases.h"

class OptimizationStrategy;
enum class StrategyType;

class Optimizer
{
public:
	Optimizer(Data& test_runs);
	void setStrategy(StrategyType new_strategy) noexcept;
	Data optimize();
private:
	std::unique_ptr<OptimizationStrategy> strategy;
	Data test_runs;
};

