#pragma once
#include "IFileReader.h"

class CsvReader : public IFileReader
{
protected:
	Data readStream(std::istream& is) override;
};