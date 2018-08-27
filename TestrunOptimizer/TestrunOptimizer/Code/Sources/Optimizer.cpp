#include "Optimizer.h"
#include "OptimizationStrategy.h"
#include "MedianStrategy.h"

Optimizer::Optimizer(Data& test_runs) : test_runs(test_runs)
{ }

void Optimizer::setStrategy(StrategyType new_strategy) noexcept
{
	switch (new_strategy)
	{
		case StrategyType::MEDIAN:
			strategy = std::make_unique<MedianStrategy>(test_runs);
		default:
			strategy = std::make_unique<MedianStrategy>(test_runs);
	}
}

Data Optimizer::optimize()
{
	return strategy->optimize();
}