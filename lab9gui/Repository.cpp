#include "Repository.h"
#include "Exception.h"
#include <algorithm>
#include <iterator>
#include <cstring>
#include<string>

int Repository::findMoviebyName(std::string movieName)
{
	int index = 0;
	for (Movie mov : this->getAllElements())
	{
		if (mov.getTitle() == movieName)
			return index;
		index++;
	}
	return -1;
}

void Repository::addMovie(Movie &newMovie)
{
	int verifyAlreadyAdded = this->findMoviebyName(newMovie.getTitle());
	if (verifyAlreadyAdded == -1)
	{
		this->adminWatchList.push_back(newMovie);
		return;
	}
	throw Exception("Movie already added! \n");
}

void Repository::deleteMovie(Movie &movieToDelete)
{
	int positionToDelete = this->findMoviebyName(movieToDelete.getTitle());
	if (positionToDelete != -1)
	{
		this->adminWatchList.erase(this->adminWatchList.begin() + positionToDelete);
		return;
	}
	throw Exception("Movie not found in the list! No modifications were made. \n");
}

void Repository::updateMovie(Movie &updatedMovie)
{
	int positionToUpdate = this->findMoviebyName(updatedMovie.getTitle());
	if (positionToUpdate != -1)
	{
		this->adminWatchList[positionToUpdate] = updatedMovie;
		return;
	}
	throw Exception("Movie not found in the list! No modifications were made. \n");
}

std::vector<Movie> Repository::getGenreLikesList(std::string genre, int minimumNumberLikes)
{
	std::vector<Movie> genreLikesList(this->adminWatchList.size());
	auto iterator = std::copy_if(this->adminWatchList.begin(), this->adminWatchList.end(), genreLikesList.begin(), [genre, minimumNumberLikes](Movie movie) {return movie.getGenre() == genre && minimumNumberLikes <= movie.getNumberLikes(); });
	genreLikesList.resize(std::distance(genreLikesList.begin(), iterator));
	return genreLikesList;
}

Repository::~Repository()
{

}
