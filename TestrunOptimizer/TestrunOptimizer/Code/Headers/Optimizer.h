#pragma once
#include <memory>
#include "TypesAliases.h"

class OptimizationStrategy;
enum class StrategyType;

class Optimizer
{
public:
	Optimizer(Data& test_runs);
	
	Optimizer() = default;
	Optimizer(const Optimizer&) = default;
	Optimizer(Optimizer&&) = default;
	Optimizer& operator=(const Optimizer&) = default;
	Optimizer& operator=(Optimizer&&) = default;
	~Optimizer() = default;

	void setStrategy(StrategyType new_strategy) noexcept;
	Data optimize();
private:
	std::unique_ptr<OptimizationStrategy> strategy;
	Data test_runs;
};

