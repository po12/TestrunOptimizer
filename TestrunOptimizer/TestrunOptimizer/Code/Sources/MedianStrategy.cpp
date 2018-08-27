#include "MedianStrategy.h"
#include <set>

MedianStrategy::MedianStrategy(Data& test_runs) : OptimizationStrategy(test_runs)
{}
double MedianStrategy::median(const std::vector<double>& times) const
{
	std::multiset<double> sorted_times { times.begin(), times.end() };
	auto mid = sorted_times.cbegin();
	auto size = sorted_times.size();

	std::advance(mid, size / 2);
	if (size % 2 == 0)
	{
		auto higher = mid--;
		return (*higher + *mid) / 2;
	}

	return *mid;
}

CalculationResult MedianStrategy::calculateNewLimit()
{
	std::map<uint8_t, double> result;
	
	for (auto &[key, val] : sorted_runs)
	{
		result[key] = median(val);
	}

	return result;
}