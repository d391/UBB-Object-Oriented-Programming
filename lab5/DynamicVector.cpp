#include "DynamicVector.h"
#include <sstream>

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new Movie[capacity];
}

void DynamicVector::setSize(int newSize)
{
	this->size = newSize;
}
void DynamicVector::setElements(Movie* elements)
{
	for (int index = 0; index < this->size; index++)
		this->elements[index] = elements[index];
}

DynamicVector DynamicVector::copyDynamicVector(DynamicVector &dynamicVectorToBeCopied)
{
	DynamicVector copy;
	copy.setSize(this->size);
	copy.setElements(this->elements);
	return copy;
}

int DynamicVector::findMoviebyName(std::string movieName)
{
	for (int index = 0; index < this->size; index++)
		if (this->elements[index].getTitle() == movieName)
			return index;
	return -1;
}

int DynamicVector::addMovie(Movie &newMovie)
{
	int verifyAlreadyAdded = this->findMoviebyName(newMovie.getTitle());
	if (verifyAlreadyAdded == -1)
	{
		this->elements[this->size] = newMovie;
		this->size++;
		return 1;
	}
	return 0;
}

int DynamicVector::deleteMovie(std::string movieName)
{
	int positionToDelete = this->findMoviebyName(movieName);
	if (positionToDelete != -1)
	{
		for (int index = positionToDelete; index < this->size - 1; index++)
			this->elements[index] = this->elements[index + 1];
		this->size--;
		return 1;
	}
	return 0;
}

int DynamicVector::updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer)
{
	int positionToUpdate = this->findMoviebyName(movieName);
	if (positionToUpdate != -1)
	{
		this->elements[positionToUpdate].setGenre(newGenre);
		this->elements[positionToUpdate].setYear(newYear);
		this->elements[positionToUpdate].setNumberLikes(newNumberLikes);
		this->elements[positionToUpdate].setTrailer(newTrailer);
		return 1;
	}
	return 0;
}



/*std::string DynamicVector::vectorString()
{
	std::stringstream vectorString;
	for (int index = 0; index < this->size; index++)
		vectorString << this->elements[index].movieString() << "\n";
	return vectorString.str();
}*/

DynamicVector::~DynamicVector()
{
	delete[] this->elements;
}
