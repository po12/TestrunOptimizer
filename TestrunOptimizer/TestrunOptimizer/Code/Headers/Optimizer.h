#pragma once
#include <memory>
#include "TypesAliases.h"

class OptimizationStrategy;
enum class StrategyType;

class Optimizer
{
public:
	Optimizer(Data& test_runs, StrategyType strategy) noexcept;
	
	Optimizer() noexcept = default;
	Optimizer(const Optimizer&) noexcept = default;
	Optimizer(Optimizer&&) noexcept = default;
	Optimizer& operator=(const Optimizer&) noexcept = default;
	Optimizer& operator=(Optimizer&&) noexcept = default;
	~Optimizer() noexcept = default;

	void setStrategy(StrategyType new_strategy) noexcept;
	Data optimize();
private:
	std::unique_ptr<OptimizationStrategy> strategy;
	Data test_runs;
};

