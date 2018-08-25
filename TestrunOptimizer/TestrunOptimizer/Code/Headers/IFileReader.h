#pragma once
#include <filesystem>
#include <iostream>

class IFileReader {
public:
	void read(std::filesystem::path&& path);
protected:
	virtual void readStream(std::istream& is) = 0;
};
