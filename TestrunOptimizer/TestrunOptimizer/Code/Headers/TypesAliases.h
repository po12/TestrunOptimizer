#pragma once
#include <vector>
#include <tuple>
#include <map>
#include "Duration.h"

using TestInfo = std::tuple<int, Duration>;
using Data = std::vector<TestInfo>;
using CalculationResult = std::map<uint8_t, double>;
using SortedRuns = std::map<uint8_t, std::vector<double>>;