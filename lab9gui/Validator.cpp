#include "Validator.h"
#include "Exception.h"
#include <cstring>


void Validator::validateMovie(const Movie& mov)
{
	std::string errorsList = "";
	if (mov.getTitle() == "" || mov.getGenre() == "" || mov.getTrailer() == "")
		errorsList += "Empty fields!\n";
	if (mov.getNumberLikes() < 0)
		errorsList += "The number of likes must pe a positive number! \n";
	if (mov.getYear() < 0)
		errorsList += "The year must be a positive number!\n";

	if (errorsList != "")
		throw Exception(errorsList);
}


Validator::~Validator()
{
}
