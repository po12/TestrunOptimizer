#pragma once
#include "IFileReader.h"

class CsvReader : public IFileReader
{
protected:
	void readStream(std::istream& is) override;
};