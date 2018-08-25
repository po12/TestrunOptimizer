#pragma once
#include <fstream>

namespace std::filesystem
{
	 class path;
}

class IFileReader {
public:
	void read(std::filesystem::path&& path);
protected:
	virtual void readStream(std::istream& is) = 0;
};
