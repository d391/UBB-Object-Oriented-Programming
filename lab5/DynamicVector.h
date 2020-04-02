#pragma once
#include "Movie.h"

class DynamicVector
{

private:
	Movie* elements;
	int size=0, capacity;

public:
	DynamicVector(int capacity = 100);
	DynamicVector copyDynamicVector(DynamicVector &dynamicVectorToBeCopied);
	int getSize() const { return this->size; };
	Movie* getAllElements() const { return this->elements; };
	void setSize(int newSize);
	void setElements(Movie* elements);
	int addMovie(Movie &newMovie);
	int findMoviebyName(std::string movieName);
	int deleteMovie(std::string movieName);
	int updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer);
	//std::string vectorString();
	~DynamicVector();

private:
	void resize();
};

