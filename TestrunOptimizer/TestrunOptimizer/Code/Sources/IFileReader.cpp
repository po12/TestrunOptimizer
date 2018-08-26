#include "IFileReader.h"
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

Data IFileReader::read(const fs::path& path)
{
	if(fs::exists(path))
	{
		std::ifstream is{ path.string(), std::ifstream::in };
		return readStream(is);
	}
	else
	{
		throw std::runtime_error("File " + path.string() + " does not exist");
	}
}