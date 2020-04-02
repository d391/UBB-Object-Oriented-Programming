#pragma once
#include "Repository.h"

class FileRepository : public Repository
{
private:
	std::string filename;
public:
	FileRepository(std::string _filename) : Repository(), filename{ _filename } { this->readFromFile(this->filename); };
	void setFilename(std::string filename) { this->filename = filename; };
	void readFromFile(std::string filename);
	void writeToFile(std::string filename);
	void addMovie(Movie& movieToAdd)override;
	void deleteMovie(Movie& movieToDelete)override;
	void updateMovie(Movie& movieToUpdate)override;
	~FileRepository();
};

