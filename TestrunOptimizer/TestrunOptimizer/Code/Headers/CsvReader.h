#pragma once
#include "IFileReader.h"

class CsvReader : public IFileReader
{
	char delim = ',';
protected:
	Data readStream(std::istream& is) override;
};