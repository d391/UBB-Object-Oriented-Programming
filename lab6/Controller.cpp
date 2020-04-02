#include "Controller.h"

int Controller::getSize()
{
	return this->repo.getSize();
}

Movie* Controller::getAllElements()
{
	return this->repo.getAllElements();
}

int Controller::addMovie(std::string title, std::string genre, int year, int numberLikes, std::string trailer)
{
	if (title == "" || genre == "" || year <= 0 || numberLikes < 0 || trailer == "")
		return -1;
	Movie movieToAdd{ title, genre, year, numberLikes, trailer };
	int success = this->repo.addMovie(movieToAdd);
	return success;
}

int Controller::deleteMovie(std::string titleToDelete)
{
	if (titleToDelete == "")
		return -1;
	int success = this->repo.deleteMovie(titleToDelete);
	return success;
}

int Controller::updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer)
{
	if (movieName == "" || newGenre == "" || newYear <= 0 || newNumberLikes < 0 || newTrailer == "")
		return -1;
	int success = this->repo.updateMovie(movieName, newGenre, newYear, newNumberLikes, newTrailer);
	return success;
}

void Controller::saveId(std::string id)
{
	this->repo.addToUserWatchList(id);
}

DynamicVectorTemplate<Movie> Controller::getGenreLikesList(std::string genre, int minimumNumberLikes)
{
	return this->repo.getGenreLikesList(genre, minimumNumberLikes);
}

Controller::~Controller()
{

}
