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
	std::string auxTitle;
	if (file.is_open())
	{
		file >> movieToAdd;
		this->addMovie(movieToAdd);
		auxTitle = movieToAdd.getTitle();
		file >> movieToAdd;
		while (movieToAdd.getTitle() != auxTitle)
		{
			auxTitle = movieToAdd.getTitle();
			this->addMovie(movieToAdd);
			file >> movieToAdd;
		}
	}
	else
		throw Exception("Cannot open file! \n");
	file.close();
}

void FileRepository::writeToFile(std::string filename)
{
	std::ofstream file(filename);
	if (file.is_open())
		for (Movie mov : this->getAllElements())
			file << mov;
	else
		throw Exception("Cannot open file! \n");
	file.close();
}

void FileRepository::addMovie(Movie & movieToAdd)
{
	int verifyAlreadyAdded = this->findMoviebyName(movieToAdd.getTitle());
	if (verifyAlreadyAdded == -1)
	{
		this->adminWatchList.push_back(movieToAdd);
		this->writeToFile(this->filename);
	}
	else
		throw Exception("Movie not found in the list! No modifications were made. \n");
}

void FileRepository::deleteMovie(Movie & movieToDelete)
{
	int positionToDelete = this->findMoviebyName(movieToDelete.getTitle());
	if (positionToDelete != -1)
	{
		this->adminWatchList.erase(this->adminWatchList.begin() + positionToDelete);
		this->writeToFile(this->filename);
	}
	else 
		throw Exception("Movie not found in the list! No modifications were made. \n");
}

void FileRepository::updateMovie(Movie & movieToUpdate)
{
	int positionToUpdate = this->findMoviebyName(movieToUpdate.getTitle());
	if (positionToUpdate != -1)
	{
		this->adminWatchList[positionToUpdate] = movieToUpdate;
		this->writeToFile(this->filename);
	}
	else
		throw Exception("Movie not found in the list! No modifications were made. \n");
}

FileRepository::~FileRepository()
{
}
