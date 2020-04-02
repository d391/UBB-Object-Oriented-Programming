#pragma once
//#include "DynamicVector.h"
#include "Repository.h"

class Controller
{

private:
	//DynamicVector& watchList;
	 Repository watchList;

public:
	Controller(Repository &watchList) : watchList{ watchList } {}
	int addMovieController(std::string title, std::string genre, int year, int numberLikes, std::string trailer);
	int deleteMovieController(std::string titleToDelete);
	int updateMovieController(std::string movieName, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer);
	Movie* getAllElementsController();
	int getSizeController();
	DynamicVectorTemplate<Movie> getUserWatchList() const { return watchList.getUserWatchList(); };
	void saveId(std::string id);
	DynamicVectorTemplate<Movie> getGenreLikesListController(std::string genre, int minimumNumberLikes);
	~Controller();
};

