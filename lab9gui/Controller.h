#pragma once
//#include "Repository.h"
#include "FileRepository.h"
#include "Validator.h"
#include "FakeRepository.h"
#include "Undo.h"
#include "Redo.h"
#include "Subject.h"

class Controller: public Subject
{

private:
	Repository *repo;
	Validator movieValidator;
	FakeRepository *userFileRepo;
	std::vector<UndoAction*> undoList;
	std::vector<RedoAction*> redoList;
	int undoIndex, redoIndex=0;

public:
	Controller() {};
	Controller(Repository* repo, Validator validator, FakeRepository *frepo) : repo{ repo }, movieValidator{ validator }, userFileRepo{ frepo } {}
	FakeRepository* getUserFileRepo() { return this->userFileRepo; };
	void setUserFilename(std::string filename);
	void setUserFileRepo(FakeRepository *newFrepo) { this->userFileRepo = newFrepo; };
	void addMovie(std::string title, std::string genre, int year, int numberLikes, std::string trailer);
	void deleteMovie(std::string titleToDelete);
	void updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer);
	void undo();
	void redo();
	std::vector<Movie> getAllElements();
	int getSize();
	std::vector<Movie> getUserWatchList() const { return this->userFileRepo->getUserWatchList(); };
	void addToUserWatchList(std::string id);
	std::vector<Movie> getGenreLikesList(std::string genre, int minimumNumberLikes);
	Movie next(int size);
	int getIndex() { return this->userFileRepo->getIndex(); };
	void reSetIndex() { this->userFileRepo->reSetIndex(); };
	~Controller();
};

