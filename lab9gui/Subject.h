#pragma once
#include <vector>
#include "Observer.h"

class Subject
{
private:
	std::vector<Observer*> vectObs;
public:
	Subject();
	void addObserver(Observer *obs) { this->vectObs.push_back(obs); };
	void notify();
	~Subject();
};

