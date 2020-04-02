#pragma once
#include <iostream>

class Movie
{

private:
	std::string title;
	std::string genre;
	int year;
	int numberLikes;
	std::string trailer;

public:
	Movie();
	Movie(std::string title, std::string genre, int year, const int numberLikes, std::string trailer);
	std::string getTitle() const { return title; };
	std::string getGenre() const { return genre; };
	int getYear() const { return year; };
	int getNumberLikes() const { return numberLikes; };
	std::string getTrailer() const { return trailer; };
	void setGenre(std::string newGenre);
	void setYear(int newYear);
	void setNumberLikes(int newNumberLikes);
	void setTrailer(std::string newTrailer);
	std::string movieString();
	friend std::istream& operator>>(std::istream& is, Movie& s);
	friend std::ostream& operator<<(std::ostream& os, Movie& s);
	~Movie();
};
