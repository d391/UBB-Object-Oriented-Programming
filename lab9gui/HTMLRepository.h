#pragma once
#include "FakeRepository.h"


class HTMLRepository : public FakeRepository
{
public:
	HTMLRepository() : FakeRepository() {};
	void writeToFile() override;
	void displayUserList() override;
	void save(Movie movieToAdd) override;
	~HTMLRepository();
};

