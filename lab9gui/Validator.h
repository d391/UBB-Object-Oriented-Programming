#pragma once
#include "Movie.h"

class Validator
{
public:
	Validator() {};
	static void validateMovie(const Movie& mov);
	~Validator();
};

