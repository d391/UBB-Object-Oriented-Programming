#include "Controller.h"

int Controller::getSizeController()
{
	return this->watchList.getSize();
}

Movie* Controller::getAllElementsController()
{
	return this->watchList.getAllElements();
}

int Controller::addMovieController(std::string title, std::string genre, int year, int numberLikes, std::string trailer)
{
	if (title == "" || genre == "" || year <= 0 || numberLikes < 0 || trailer == "")
		return -1;
	Movie movieToAdd{title, genre, year, numberLikes, trailer};
	int success = this->watchList.addMovie(movieToAdd);
	return success;
}

int Controller::deleteMovieController(std::string titleToDelete)
{
	if (titleToDelete == "")
		return -1;
	int success = this->watchList.deleteMovie(titleToDelete);
	return success;
}

int Controller::updateMovieController(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer)
{
	if (movieName == "" || newGenre == "" || newYear <= 0 || newNumberLikes < 0 || newTrailer == "")
		return -1;
	int success = this->watchList.updateMovie(movieName, newGenre, newYear, newNumberLikes, newTrailer);
	return success;
}

void Controller::saveId(std::string id)
{
	this->watchList.addToUserWatchList(id);
}

DynamicVectorTemplate<Movie> Controller::getGenreLikesListController(std::string genre, int minimumNumberLikes)
{
	return this->watchList.getGenreLikesList(genre, minimumNumberLikes);
}

Controller::~Controller()
{
	
}
