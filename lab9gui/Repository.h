#pragma once
#include "Movie.h"
#include <vector>

class Repository
{
protected:
	std::vector<Movie> adminWatchList;
public:
	Repository() {}
	int getSize() const { return this->adminWatchList.size(); };
	std::vector<Movie> getAllElements() const { return this->adminWatchList; };
	int findMoviebyName(std::string movieName);
	virtual void addMovie(Movie &newMovie);
	virtual void deleteMovie(Movie &movieToDelete);
	virtual void updateMovie(Movie &updatedMovie);
	std::vector<Movie> getGenreLikesList(std::string genre, int minimumNumberLikes);
	~Repository();
};

