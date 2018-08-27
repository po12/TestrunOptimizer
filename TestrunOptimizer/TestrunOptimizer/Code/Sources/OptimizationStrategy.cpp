#include "OptimizationStrategy.h"
#include <numeric>
#include <algorithm>

OptimizationStrategy::OptimizationStrategy(Data& test_runs) : test_runs(test_runs)
{
}

double OptimizationStrategy::mean(const std::vector<double>& times) const
{
	auto sum = std::accumulate(times.begin(), times.end(), 0.0);
	return sum / times.size();
}

double OptimizationStrategy::standardDeviation(const std::vector<double>& times) const
{
	std::vector<double> diff(times.size());

	auto times_mean = mean(times);
	std::transform(times.begin(), times.end(), diff.begin(), 
		[times_mean](double x) {return x - times_mean; });
	
	auto square_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
	return std::sqrt(square_sum / times.size());
}
void OptimizationStrategy::threeSdLaw(std::vector<double>& times, double sd)
{
	times.erase(std::remove_if(times.begin(), times.end(),
		[sd](auto time) { return time <= sd * -3 || time >= sd * 3; }), times.end());
}

void OptimizationStrategy::prepareData()
{
	for (auto& test_run : test_runs)
	{
		auto test_id = std::get<0>(test_run);
		double duration = std::get<1>(test_run);

		sorted_runs[test_id].emplace_back(duration);
	}

	for (auto &[key, val] : sorted_runs)
	{
		threeSdLaw(val, standardDeviation(val));
	}
}

Data OptimizationStrategy::mergeData()
{
	return {};
}

Data OptimizationStrategy::optimize()
{
	prepareData();
	calculateNewLimit();
	return mergeData();
}