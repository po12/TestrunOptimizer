#pragma once
#include "IFileReader.h"

class CsvReader : public IFileReader
{
public:
	CsvReader() noexcept = default;
	CsvReader(const CsvReader&) noexcept = default;
	CsvReader(CsvReader&&) noexcept = default;
	CsvReader& operator=(const CsvReader&) = default;
	CsvReader& operator=(CsvReader&&) = default;
	virtual ~CsvReader() = default;
protected:
	Data readStream(std::istream& is) override;
};