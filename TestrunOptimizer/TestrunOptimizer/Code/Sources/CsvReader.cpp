#include "CsvReader.h"
#include <tuple>
#include <sstream>

Data CsvReader::readStream(std::istream& is)
{
	Data l_result;
	
	uint32_t test_id;
	char delim;
	Duration dur;

	std::string line;
	while(std::getline(is, line))
	{
		std::stringstream sstream{ line };
		sstream >> test_id >> delim >> dur;
		l_result.emplace_back(test_id, dur);
	}
	
	return l_result;
}