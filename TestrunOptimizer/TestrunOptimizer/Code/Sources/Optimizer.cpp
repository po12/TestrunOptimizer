#include "Optimizer.h"
#include "OptimizationStrategy.h"

void Optimizer::setStrategy(std::unique_ptr<OptimizationStrategy> new_strategy) noexcept
{
	strategy = std::move(new_strategy);
}

Data Optimizer::optimize()
{
	return strategy->optimize();
}