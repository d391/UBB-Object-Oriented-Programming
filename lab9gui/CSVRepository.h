#pragma once
#include "FakeRepository.h"

class CSVRepository : public FakeRepository
{
public:
	CSVRepository() : FakeRepository() {};
	void writeToFile() override;
	void displayUserList() override;
	void save(Movie movieToAdd) override;
	~CSVRepository();
};

