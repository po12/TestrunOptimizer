#include "CsvReader.h"
#include <tuple>

Data CsvReader::readStream(std::istream& is)
{
	uint32_t test_id;
	char delim;
	Duration dur;
	is >> test_id >> delim >> dur;
	return { std::tie(test_id, dur) };
}