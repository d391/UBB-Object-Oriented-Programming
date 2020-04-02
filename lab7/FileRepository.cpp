#include "FileRepository.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Exception.h"

void FileRepository::readFromFile(std::string filename)
{
	std::ifstream file(filename);
	Movie movieToAdd;
	if (file.is_open())
		while (!file.eof())
		{
			file >> movieToAdd;
			this->addMovie(movieToAdd);
		}
	else
		throw Exception("Cannot open file! \n");
	file.close();
}

void FileRepository::writeToFile(std::string filename)
{
	std::ofstream file(filename);
	if(file.is_open())
		for (Movie mov : this->getAllElements())
			file << mov;
	else
		throw Exception("Cannot open file! \n");
	file.close();
}

FileRepository::~FileRepository()
{
	
}
