#pragma once
#include <memory>
#include "TypesAliases.h"

class OptimizationStrategy;

class Optimizer
{
public:
	void setStrategy(std::unique_ptr<OptimizationStrategy> new_strategy) noexcept;
	Data optimize();
private:
	std::unique_ptr<OptimizationStrategy> strategy;
};

