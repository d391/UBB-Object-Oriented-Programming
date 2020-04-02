#include "ui.h"
#include <iostream>
#include <cstring>
#include <string>

void ui::administratorMenu()
{
	std::cout << "Type: " << std::endl;
	std::cout << "	mode X(e.g.mode A)" << std::endl;
	std::cout << "	add title, genre, yearOfRelease, likes, trailer" << std::endl;
	std::cout << "	update title, newGenre, newYearOfRelease, newLikes, newTrailer" << std::endl;
	std::cout << "	delete title" << std::endl;
	std::cout << "	list" << std::endl;
	std::cout << "	exit" << std::endl;
	std::cout << std::endl;
}

void ui::userMenu()
{
	std::cout << "Type: " << std::endl;
	std::cout << "	mode X(e.g.mode A)" << std::endl;
	std::cout << "	next" << std::endl;
	std::cout << "	save id(e.g.save Equilibrium) "<< std::endl;
	std::cout << "	list genre, likes(e.g.Sci - Fi, 5000)" << std::endl;
	std::cout << "	mylist" << std::endl;
	std::cout << "	exit" << std::endl;
}

void ui::listMovies(DynamicVectorTemplate<Movie> listOfMovies)
{
	for (int index = 0; index < listOfMovies.getSize(); index++)
		std::cout << listOfMovies.getAllElements()[index].movieString() << std::endl;
	std::cout << std::endl;
}

void ui::listUserWatchList()
{
	this->listMovies(this->controller.getUserWatchList());
}

void ui::listGenreLikes(std::string genre, int minimumNumberOfLikes)
{
	
}

void ui::addMovieUI(std::string titleToAdd, std::string genreToAdd, int yearToAdd, int numberLikesToAdd, std::string trailerToAdd)
{
	int success = this->controller.addMovieController(titleToAdd, genreToAdd, yearToAdd, numberLikesToAdd, trailerToAdd);
	if (success == 0)
		std::cout << "Movie already added!" << std::endl;
	else if (success == -1)
		std::cout << "Movie data not vallid!" << std::endl;
	else
		std::cout << "Movie added to the watch list! " << std::endl;
}

void ui::deleteMovieUI(std::string titleToDelete)
{
	int success = this->controller.deleteMovieController(titleToDelete);
	if (success == 0)
		std::cout << "Movie not found in the list! No modifications were made." << std::endl;
	else if (success == -1)
		std::cout << "Movie title not valid!" << std::endl;
	else
		std::cout << "Movie deleted from the watch list!" << std::endl;
}
void ui::updateMovieUI(std::string titleToUpdate, std::string newGenre, int newYear, int newNumberLikes, std::string newTrailer)
{
	int success = this->controller.updateMovieController(titleToUpdate, newGenre, newYear, newNumberLikes, newTrailer);
	if (success == 0)
		std::cout << "Movie not found in the list! No modifications were made." << std::endl;
	else if (success == -1)
		std::cout << "Movie data not vallid!" << std::endl;
	else
		std::cout << "Movie updated! " << std::endl;
}

void ui::next(int size)
{
	this->index++;
	if (this->index == size)
		this->index = 0;
}

void ui::printCurrent(Movie* currentList)
{
	std::cout << currentList[this->index].movieString() << std::endl;
}

void ui::processCommand(char *command, char *chosenMode)
{
	if (strcmp(chosenMode, "A") == 0)
	{
		if (strcmp(command, "list") == 0)
			for (int index = 0; index < this->controller.getSizeController(); index++)
			{
				std::cout << "Title: " << this->controller.getAllElementsController()[index].getTitle() << std::endl;
				std::cout << "Genre: " << this->controller.getAllElementsController()[index].getGenre() << std::endl;
				std::cout << "Year of release: " << this->controller.getAllElementsController()[index].getYear() << std::endl;
				std::cout << "Number of likes: " << this->controller.getAllElementsController()[index].getNumberLikes() << std::endl;
				std::cout << "Trailer link: " << this->controller.getAllElementsController()[index].getTrailer() << std::endl;
				std::cout << std::endl;
			}
		else
		{
			char *commandType;
			commandType = strtok(command, " ");
			if (strcmp(commandType, "add") == 0)
			{
				char parameters[5][70], *parameterToken;
				int parameterNumber = 0;
				parameterToken = strtok(NULL, ", ");
				while (parameterToken != NULL)
				{
					strcpy(parameters[parameterNumber], parameterToken);
					parameterNumber++;
					parameterToken = strtok(NULL, ", ");
				}
				addMovieUI(parameters[0], parameters[1], atoi(parameters[2]), atoi(parameters[3]), parameters[4]);
			}
			else if (strcmp(commandType, "delete") == 0)
			{
				char *parameter;
				parameter = strtok(NULL, " ");
				deleteMovieUI(parameter);
			}
			else if (strcmp(commandType, "update") == 0)
			{
				char parameters[5][70], *parameterToken;
				int parameterNumber = 0;
				parameterToken = strtok(NULL, ", ");
				while (parameterToken != NULL)
				{
					strcpy(parameters[parameterNumber], parameterToken);
					parameterNumber++;
					parameterToken = strtok(NULL, ", ");
				}
				updateMovieUI(parameters[0], parameters[1], atoi(parameters[2]), atoi(parameters[3]), parameters[4]);
			}
		}
	}
	else
	{
		if (strcmp(command, "next") == 0)
		{
			//if (this->minimumNumberLikes == 0)
				//this->next(this->controller.getSizeController());
			//else
			this->printCurrent(this->controller.getAllElementsController());
			this->next(this->controller.getGenreLikesListController(this->genre, this->minimumNumberLikes).getSize());
		}
		else if(strcmp(command, "myList") == 0)
		{
			this->listUserWatchList();
		}
		else
		{
			char *commandType;
			commandType = strtok(command, " ");
			if (strcmp(commandType, "save") == 0)
			{
				char *parameter;
				parameter = strtok(NULL, " ");
				this->controller.saveId(parameter);
			}
			else if (strcmp(commandType, "list") == 0)
			{
				this->genre = strtok(NULL, ", ");
				this->minimumNumberLikes = atoi(strtok(NULL, ", "));
				this->listMovies(this->controller.getGenreLikesListController(this->genre, this->minimumNumberLikes));
			}
			else
				this->listUserWatchList();
		}
	}
}


int ui::run()
{
	char chosenMode[] = "X";
	char command[100];
	this->index = 0;
	std::cout << "Please type mode A for admin mode or mode B for user mode!" << std::endl;
	while (1)
	{
		if (strcmp(chosenMode, "A") == 0)
			administratorMenu();
		else if (strcmp(chosenMode, "B") == 0)
		{
			userMenu();
			if (this->controller.getSizeController() == 0)
				std::cout << "Empty movie list! Enter mode A to add some movies! " << std::endl;
			//else if (this->minimumNumberLikes == 0)
			
			//else
				//this->printCurrent(this->controller.getGenreLikesListController(this->genre, this->minimumNumberLikes).getAllElements());
		}
		std::cout << "Enter command: ";
		std::cin.get(command, 100);
		std::cin.get();
		if (strcmp(command, "exit") == 0)
			return 1;
		else
		{
			char commandAux[100];
			strcpy(commandAux, command);
			char *commandType;
			commandType = strtok(command, " ");
			if (strcmp(commandType, "mode") == 0)
			{
				char *parameter;
				parameter = strtok(NULL, " ");
				strcpy(chosenMode, parameter);
				if (strcmp(chosenMode, "A") != 0 && strcmp(chosenMode, "B") != 0)
					std::cout << "Invalid mode! Please reenter command";
			}
			else
				if (strcmp(chosenMode, "A") == 0 || strcmp(chosenMode, "B") == 0)
					processCommand(commandAux, chosenMode);
				else
					std::cout << "Invalid mode or mode not chosen!" << std::endl;
		}			
	}
}

ui::~ui()
{
}
