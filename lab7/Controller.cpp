#include "Controller.h"

int Controller::getSize()
{
	return this->repo.getSize();
}

std::vector<Movie> Controller::getAllElements()
{
	return this->repo.getAllElements();
}

void Controller::setUserFilename(std::string filename)
{
	this->userFileRepo->setFilename(filename);
}

void Controller::addMovie(std::string title, std::string genre, int year, int numberLikes, std::string trailer)
{
	Movie movieToAdd{ title, genre, year, numberLikes, trailer };
	this->movieValidator.validateMovie(movieToAdd);
	return this->repo.addMovie(movieToAdd);
}

void Controller::deleteMovie(std::string titleToDelete)
{
	Movie movieToDelete{ titleToDelete, "", 1, 1, "" };
	return this->repo.deleteMovie(movieToDelete);
}

void Controller::updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer)
{
	Movie updatedMovie{ movieName, newGenre, newYear, newNumberLikes, newTrailer };
	this->movieValidator.validateMovie(updatedMovie);
	this->repo.updateMovie(updatedMovie);
}

void Controller::addToUserWatchList(std::string id)
{
	Movie movieToAdd;
	int index = this->repo.findMoviebyName(id);
	movieToAdd = this->repo.getAllElements()[index];
	this->userFileRepo->save(movieToAdd);
}

std::vector<Movie> Controller::getGenreLikesList(std::string genre, int minimumNumberLikes)
{
	return this->repo.getGenreLikesList(genre, minimumNumberLikes);
}

Movie Controller::next()
{
	int index = this->userFileRepo->next(this->getSize());
	return this->getAllElements()[index];
}

void Controller::writeToFile(std::string filename)
{
	return this->repo.writeToFile(filename);
}

void Controller::readFromFile(std::string filename)
{
	return this->repo.readFromFile(filename);
}

Controller::~Controller()
{

}
