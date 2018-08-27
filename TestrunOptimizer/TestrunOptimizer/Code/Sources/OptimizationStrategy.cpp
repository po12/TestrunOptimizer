#include "OptimizationStrategy.h"
#include <numeric>
#include <algorithm>

OptimizationStrategy::OptimizationStrategy(Data& test_runs) : test_runs(test_runs)
{
}

double OptimizationStrategy::mean(const std::vector<double>& times)
{
	auto sum = std::accumulate(times.begin(), times.end(), 0.0);
	return sum / times.size();
}

double OptimizationStrategy::standardDeviation(const std::vector<double>& times)
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
	const auto mean_time = mean(times);
	const auto third_deviation = 3 * sd;
	times.erase(std::remove_if(times.begin(), times.end(),
		[third_deviation, mean_time](auto time) 
		{
			return time <= mean_time - third_deviation || time >= mean_time + third_deviation; 
		}), times.end());
}

void OptimizationStrategy::prepareData()
{
	for (auto& test_run : test_runs)
	{
		auto test_id = std::get<0>(test_run);
		sorted_runs[test_id].emplace_back(std::get<1>(test_run));
	}

	for (auto &[key, val] : sorted_runs)
	{
		threeSdLaw(val, standardDeviation(val));
	}
}

Data OptimizationStrategy::mergeData(const CalculationResult& calculation_results)
{
	Data result;

	for (const auto&[key, val]  : calculation_results)
	{
		result.push_back({ key, Duration{ val }});
	}
	
	return result;
}

Data OptimizationStrategy::optimize()
{
	prepareData();
	auto new_limits = calculateNewLimit();
	return mergeData(new_limits);
}