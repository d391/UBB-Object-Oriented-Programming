#pragma once
//#include "DynamicVector.h"
#include "Repository.h"

class Controller
{

private:
	//DynamicVector& watchList;
	Repository repo;

public:
	Controller(Repository &repo) : repo{ repo } {}
	int addMovie(std::string title, std::string genre, int year, int numberLikes, std::string trailer);
	int deleteMovie(std::string titleToDelete);
	int updateMovie(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer);
	Movie* getAllElements();
	int getSize();
	DynamicVectorTemplate<Movie> getUserWatchList() const { return repo.getUserWatchList(); };
	void saveId(std::string id);
	DynamicVectorTemplate<Movie> getGenreLikesList(std::string genre, int minimumNumberLikes);
	~Controller();
};

