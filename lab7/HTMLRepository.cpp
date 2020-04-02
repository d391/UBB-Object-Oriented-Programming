#include "HTMLRepository.h"
#include <fstream>
#include <Windows.h>


void HTMLRepository::writeToFile()
{
	std::ofstream file(this->filename);
	file << "<!DOCTYPE html>" << std::endl;
	file << "<html>" << std::endl;
	file << "	<head>" << std::endl;
	file << "		<title>User Watchlist</title>" << std::endl;
	file << "	</head>" << std::endl;
	file << "<body>" << std::endl;
	file << "	<table border = \"1\">" << std::endl;
	file << "		<tr>" << std::endl;
	file << "			<td>Title</td>" << std::endl;
	file << "			<td>Genre</td>" << std::endl;
	file << "			<td>Year</td>" << std::endl;
	file << "			<td>Number of likes</td>" << std::endl;
	file << "			<td>Trailer link</td>" << std::endl;
	file << "		</tr>" << std::endl;
	for (Movie mov : this->userWatchList)
	{
		file << "		<tr>" << std::endl;
		file << "			<td>" << mov.getTitle() << "</td>" << std::endl;
		file << "			<td>" << mov.getGenre() << "</td>" << std::endl;
		file << "			<td>" << mov.getYear() << "</td>" << std::endl;
		file << "			<td>" << mov.getNumberLikes() << "</td>" << std::endl;
		file << "			<td> <a href = " << mov.getTrailer() << ">Link</a> </td>" << std::endl;
		file << "		</tr>" << std::endl;
	}
	file << "	</table>" << std::endl;
	file << "</body>" << std::endl;
	file << "</html>" << std::endl;
	file.close();
}

void HTMLRepository::displayUserList()
{
	std::string aux = "start " + this->filename;
	system(aux.c_str());
}

void HTMLRepository::save(Movie movieToAdd)

{
	this->userWatchList.push_back(movieToAdd);
	this->writeToFile();
}

HTMLRepository::~HTMLRepository()
{

}
