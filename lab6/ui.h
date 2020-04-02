#pragma once
#include "Controller.h"

class ui
{

private:
	Controller controller;
	int index;
	std::string genre;
	int minimumNumberLikes = 0;

public:
	ui(const Controller &controller) : controller(controller) {}
	int run();
	~ui();

private:
	void administratorMenu();
	void userMenu();
	void addMovie(std::string titleToAdd, std::string genreToAdd, int yearToAdd, int numberLikesToAdd, std::string trailerToAdd);
	void deleteMovie(std::string titleToDelete);
	void updateMovie(std::string titleToUpdate, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer);
	void processCommand(char *command, char *chosenMode);
	void listUserWatchList();
	void listMovies(DynamicVectorTemplate<Movie> listOfMovies);
	void next(int size);
	void printCurrent(Movie* currentList);
};

