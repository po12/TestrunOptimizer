#pragma once
#include <fstream>
#include "TypesAliases.h"

namespace std::filesystem
{
	 class path;
}

class IFileReader {
public:
	Data read(const std::filesystem::path&);
	virtual ~IFileReader() = default;
protected:
	virtual Data readStream(std::istream&) = 0;
};
