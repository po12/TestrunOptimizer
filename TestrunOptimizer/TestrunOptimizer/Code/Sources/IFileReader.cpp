#include <filesystem>
#include "IFileReader.h"

Data IFileReader::read(const std::filesystem::path& path)
{
	if(std::filesystem::exists(path))
	{
		std::ifstream is{ path.string(), std::ifstream::in };
		return readStream(is);
	}
	else
	{
		throw std::runtime_error("File " + path.string() + " does not exist");
	}
}