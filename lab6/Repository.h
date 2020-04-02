#pragma once
#include "Movie.h"
#include "DynamicVectorTemplate.h"

class Repository
{
private:
	DynamicVectorTemplate<Movie> movies;
	DynamicVectorTemplate<Movie> userWatchList;
public:
	Repository() {}
	int getSize() const { return this->movies.getSize(); };
	Movie* getAllElements() const { return this->movies.getAllElements(); };
	DynamicVectorTemplate<Movie> getUserWatchList() const { return this->userWatchList; };
	int findMoviebyName(std::string movieName);
	int addMovie(Movie &newMovie);
	int deleteMovie(std::string movieName);
	int updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer);
	void addToUserWatchList(std::string id);
	DynamicVectorTemplate<Movie> getGenreLikesList(std::string genre, int minimumNumberLikes);
	~Repository();
};

