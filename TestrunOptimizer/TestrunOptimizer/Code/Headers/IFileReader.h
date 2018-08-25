#pragma once
#include <vector>
#include "Duration.h"

using TestInfo = std::tuple<int, Duration>;
using Data = std::vector<TestInfo>;

namespace std::filesystem
{
	 class path;
}

class IFileReader {
public:
	Data read(const std::filesystem::path&);
protected:
	virtual Data readStream(std::istream&) = 0;
};
