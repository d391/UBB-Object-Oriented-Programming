#include "Controller.h"
#include "Exception.h"

int Controller::getSize()
{
	return this->repo->getSize();
}

std::vector<Movie> Controller::getAllElements()
{
	return this->repo->getAllElements();
}

void Controller::setUserFilename(std::string filename)
{
	this->userFileRepo->setFilename(filename);
}

void Controller::addMovie(std::string title, std::string genre, int year, int numberLikes, std::string trailer)
{
	Movie movieToAdd{ title, genre, year, numberLikes, trailer };
	this->movieValidator.validateMovie(movieToAdd);
	this->undoList.push_back(new UndoAdd{ movieToAdd, *this->repo });
	this->redoList.push_back(new RedoAdd{ movieToAdd, *this->repo });
	this->redoIndex++;
	this->undoIndex++;
	return this->repo->addMovie(movieToAdd);
}

void Controller::deleteMovie(std::string titleToDelete)
{
	Movie movieToDelete = this->getAllElements()[this->repo->findMoviebyName(titleToDelete)];
	this->undoList.push_back(new UndoDelete{ movieToDelete, *this->repo });
	this->redoList.push_back(new RedoDelete{ movieToDelete, *this->repo });
	this->undoIndex++;
	this->redoIndex++;
	return this->repo->deleteMovie(movieToDelete);
}

void Controller::updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer)
{
	Movie updatedMovie{ movieName, newGenre, newYear, newNumberLikes, newTrailer };
	this->movieValidator.validateMovie(updatedMovie);
	this->undoList.push_back(new UndoUpdate{ this->getAllElements()[this->repo->findMoviebyName(movieName)], *this->repo });
	this->redoList.push_back(new RedoUpdate{ updatedMovie, *this->repo });
	this->redoIndex++;
	this->undoIndex++;
	this->repo->updateMovie(updatedMovie);
}

void Controller::undo()
{
	if (this->undoList.size() != 0)
	{
		UndoAction* action = this->undoList[this->undoList.size() - 1];
		action->doUndo();
		this->undoList.pop_back();
		this->redoIndex = this->undoList.size();
		//if (this->undoList.size() == this->redoList.size() - 2)
			//this->redoList.pop_back();
	}
	else throw Exception("No more undos!");
}

void Controller::redo()
{
	if (this->redoList.size() != 0 && this->redoIndex < this->redoList.size())
	{
		RedoAction *action = this->redoList[this->redoIndex];
		action->doRedo();
		//this->redoList.pop_back();
		this->redoList.erase(this->redoList.begin() + this->redoIndex);
		this->redoIndex = this->undoList.size();
	}
	else throw Exception("No more redos!");
}

void Controller::addToUserWatchList(std::string id)
{
	Movie movieToAdd;
	int index = this->repo->findMoviebyName(id);
	movieToAdd = this->repo->getAllElements()[index];
	this->userFileRepo->save(movieToAdd);
	this->notify();
}

std::vector<Movie> Controller::getGenreLikesList(std::string genre, int minimumNumberLikes)
{
	return this->repo->getGenreLikesList(genre, minimumNumberLikes);
}

Movie Controller::next(int size)
{
	int index = this->userFileRepo->next(size);
	return this->getAllElements()[index];
}

Controller::~Controller()
{

}
