#include "IFileReader.h"
#include <filesystem>
#include <sstream>

void IFileReader::read(std::filesystem::path&& path)
{
	if(std::filesystem::exists(path))
	{
		std::ifstream is{ path.c_str(), std::ifstream::in };
		readStream(is);
	}
	else
	{
		std::ostringstream msg;
		msg << "File " << path.c_str() << " does not exist";
		throw std::runtime_error(msg.str());
	}
}