#pragma once
#include "tests.h"
#include "ui.h"
#include <iostream>
#include <string>

int main()
{
	testMovie();
	testDynamicVector();
	testController();
	Repository movies{};
	/*Movie m1{ "title1", "genre", 2019, 2000, "trailer1" };
	Movie m2{ "title2", "genre", 2019, 2000, "trailer2" };
	Movie m3{ "title3", "genre3", 2019, 2000, "trailer3" };
	Movie m4{ "title4", "genre4", 2019, 2000, "trailer4" };
	movies.addMovie(m1);
	movies.addMovie(m2);
	movies.addMovie(m3);
	movies.addMovie(m4);*/
	Controller controller{ movies };
	ui ui{ controller };
	ui.run();
	return 0;
}