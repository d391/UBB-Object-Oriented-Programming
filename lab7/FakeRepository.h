#pragma once
#include <string>
#include <vector>
#include "Movie.h"
#include "UserRepo.h"


class FakeRepository: public UserRepo
{
protected:
	std::string filename;
public:
	FakeRepository() : UserRepo() {};
	void setFilename(std::string filename) { this->filename = filename; };
	virtual void writeToFile() = 0;
	virtual void displayUserList() = 0;
	virtual ~FakeRepository();
};

