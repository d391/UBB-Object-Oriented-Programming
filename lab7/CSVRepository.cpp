#include "CSVRepository.h"
#include <fstream>
#include <Windows.h>


void CSVRepository::writeToFile()
{
	std::ofstream file(this->filename);
	if(file.is_open())
		for (Movie mov : this->userWatchList)
			file << mov.getTitle() << "," << mov.getGenre() << "," << mov.getYear() << "," << mov.getNumberLikes() << "," << mov.getTrailer() << std::endl;
	file.close();
}

void CSVRepository::displayUserList()
{
	std::string aux = "start " + this->filename;
	system(aux.c_str());
}

void CSVRepository::save(Movie movieToAdd)
{
	this->userWatchList.push_back(movieToAdd);
	this->writeToFile();
}

CSVRepository::~CSVRepository()
{
}
