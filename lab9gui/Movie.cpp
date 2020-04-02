#include "Movie.h"
#include <string.h>
#include <sstream>
#include <vector>

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
	movieString << "Title: " << this->title << std::endl << "Genre: " << this->genre << std::endl << "Year: " << this->year << std::endl << "Number of likes: " << this->numberLikes << std::endl << "Trailer link: " << this->trailer << std::endl;
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

std::istream& operator>>(std::istream& is, Movie& movie)
{
	std::string line;
	getline(is, line);

	std::vector<std::string> tokens;
	std::stringstream ss(line);
	std::string token;
	while (getline(ss, token, ','))
		tokens.push_back(token);

	if (tokens.size() != 5)
		return is;

	movie.title = tokens[0];
	movie.genre = tokens[1];
	movie.year = stoi(tokens[2]);
	movie.numberLikes = stoi(tokens[3]);
	movie.trailer = tokens[4];

	return is;
}

std::ostream& operator<<(std::ostream& os, Movie& movie)
{
	os << movie.title << "," << movie.genre << "," << movie.year << "," << movie.numberLikes << "," << movie.trailer << std::endl;
	return os;
}

Movie::~Movie()
{

}
