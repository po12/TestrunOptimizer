#include "IFileReader.h"
#include <filesystem>
#include <sstream>
#include <iostream>
namespace fs = std::filesystem;

Data IFileReader::read(const fs::path& path)
{
	const auto rel_path = fs::absolute(path);
	if(fs::exists(rel_path))
	{
		std::ifstream is{ rel_path.string(), std::ifstream::in };
		return readStream(is);
	}
	else
	{
		std::ostringstream msg;
		msg << "File " << rel_path.string() << " does not exist";
		throw std::runtime_error(msg.str());
	}
}