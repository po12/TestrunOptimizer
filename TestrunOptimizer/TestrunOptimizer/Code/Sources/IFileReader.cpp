#include "IFileReader.h"
#include <filesystem>
#include <sstream>
#include <iostream>
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
		std::ostringstream msg;
		msg << "File " << path.string() << " does not exist";
		throw std::runtime_error(msg.str());
	}
}