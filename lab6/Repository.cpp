#include "Repository.h"

int Repository::findMoviebyName(std::string movieName)
{
	for (int index = 0; index < this->getSize(); index++)
		if (this->getAllElements()[index].getTitle() == movieName)
			return index;
	return -1;
}

int Repository::addMovie(Movie &newMovie)
{
	int verifyAlreadyAdded = this->findMoviebyName(newMovie.getTitle());
	if (verifyAlreadyAdded == -1)
	{
		this->movies.addElement(newMovie);
		return 1;
	}
	return 0;
}

int Repository::deleteMovie(std::string movieName)
{
	int positionToDelete = this->findMoviebyName(movieName);
	if (positionToDelete != -1)
	{
		this->movies.deleteElement(positionToDelete);
		return 1;
	}
	return 0;
}

int Repository::updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer)
{
	int positionToUpdate = this->findMoviebyName(movieName);
	if (positionToUpdate != -1)
	{
		Movie updatedMovie{ movieName, newGenre, newYear, newNumberLikes, newTrailer };
		this->movies.updateElement(positionToUpdate, updatedMovie);
		return 1;
	}
	return 0;
}

void Repository::addToUserWatchList(std::string id)
{
	int positionOfMovieToAdd = this->findMoviebyName(id);
	this->userWatchList.addElement(this->movies.getAllElements()[positionOfMovieToAdd]);
}

DynamicVectorTemplate<Movie> Repository::getGenreLikesList(std::string genre, int minimumNumberLikes)
{
	DynamicVectorTemplate<Movie> genreLikesList;
	for (int index = 0; index < this->getSize(); index++)
		if (this->getAllElements()[index].getGenre() == genre && minimumNumberLikes <= this->getAllElements()[index].getNumberLikes())
			genreLikesList.addElement(this->getAllElements()[index]);
	return genreLikesList;
}

Repository::~Repository()
{

}
