#include "UserRepo.h"

UserRepo::UserRepo()
{
}

int UserRepo::next(int size)
{
	this->currentIndex++;
	if (this->currentIndex == size)
		this->currentIndex = 0;
	return this->currentIndex;
}
void UserRepo::save(Movie movieToAdd)
{
	this->userWatchList.push_back(movieToAdd);
}

void UserRepo::mylist()
{

}

UserRepo::~UserRepo()
{
}
