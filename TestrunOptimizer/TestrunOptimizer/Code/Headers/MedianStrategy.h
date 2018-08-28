#pragma once
#include "OptimizationStrategy.h"
#include "TypesAliases.h"

class MedianStrategy : public OptimizationStrategy
{
public:
	MedianStrategy(Data& test_runs) noexcept;
	
	MedianStrategy() noexcept = default;
	MedianStrategy(const MedianStrategy&) noexcept = default;
	MedianStrategy(MedianStrategy&&) noexcept = default;
	MedianStrategy& operator=(const MedianStrategy&) noexcept = default;
	MedianStrategy& operator=(MedianStrategy&&) noexcept = default;
	virtual ~MedianStrategy() = default;
protected:
	CalculationResult calculateNewLimit() override;
private:
	double median(const std::vector<double>& times) const;
};

