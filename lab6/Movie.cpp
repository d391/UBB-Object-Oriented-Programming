#include "Movie.h"
#include <string.h>
#include <sstream>

Movie::Movie() :title(""), year(0), numberLikes(0), trailer("") {}

Movie::Movie(std::string title, std::string genre, int year, const int numberLikes, std::string trailer)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->numberLikes = numberLikes;
	this->trailer = trailer;
}

std::string Movie::movieString()
{
	std::stringstream movieString;
	movieString << "Title: " << this->title << " - Genre: " << this->genre << " - Year: " << this->year << " - Number of likes: " << this->numberLikes << " - Trailer link: " << this->trailer << std::endl;
	return movieString.str();
}

void Movie::setGenre(std::string newGenre)
{
	this->genre = newGenre;
}

void Movie::setYear(int newYear)
{
	this->year = newYear;
}

void Movie::setNumberLikes(int newNumberLikes)
{
	this->numberLikes = newNumberLikes;
}

void Movie::setTrailer(std::string newTrailer)
{
	this->trailer = newTrailer;
}

Movie::~Movie()
{

}
