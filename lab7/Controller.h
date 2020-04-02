#pragma once
//#include "Repository.h"
#include "FileRepository.h"
#include "Validator.h"
#include "FakeRepository.h"

class Controller
{

private:
	//Repository repo;
	FileRepository repo;
	Validator movieValidator;
	FakeRepository *userFileRepo;

public:
	Controller(FileRepository &repo, Validator validator, FakeRepository *frepo) : repo{ repo }, movieValidator{ validator }, userFileRepo{frepo} {}
	FakeRepository* getUserFileRepo() { return this->userFileRepo; };
	//void setMainFilename(std::string filename) { this->userFileRepsetFilename(); };
	void setUserFilename(std::string filename);
	void setUserFileRepo(FakeRepository *newFrepo) { this->userFileRepo = newFrepo; };
	void addMovie(std::string title, std::string genre, int year, int numberLikes, std::string trailer);
	void deleteMovie(std::string titleToDelete);
	void updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer);
	std::vector<Movie> getAllElements();
	int getSize();
	std::vector<Movie> getUserWatchList() const { return this->userFileRepo->getUserWatchList(); };
	void addToUserWatchList(std::string id);
	std::vector<Movie> getGenreLikesList(std::string genre, int minimumNumberLikes);
	Movie next();
	void writeToFile(std::string filename);
	void readFromFile(std::string filename);
	~Controller();
};

