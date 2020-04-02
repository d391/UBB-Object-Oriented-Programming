#pragma once
#include "Movie.h"
#include <vector>
#include <string>

class UserRepo
{
protected:
	int currentIndex = -1;
	std::vector<Movie> userWatchList;
public:
	UserRepo();
	std::vector<Movie> getUserWatchList() { return this->userWatchList; };
	int getIndex() { return this->currentIndex; };
	int next(int size);
	virtual void save(Movie movieToAdd);
	void mylist();
	void reSetIndex() { this->currentIndex = -1; };
	~UserRepo();
};

