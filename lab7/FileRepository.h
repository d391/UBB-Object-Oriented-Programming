#pragma once
#include "Repository.h"

class FileRepository: public Repository
{
private:
	std::string filename;
public:
	FileRepository() : Repository() {};
	void setFilename(std::string filename) { this->filename = filename; };
	void readFromFile(std::string filename);
	void writeToFile(std::string filename);
	~FileRepository();
};

