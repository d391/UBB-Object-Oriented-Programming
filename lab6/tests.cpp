#pragma once
#include "tests.h"
#include <iostream>
#include <string>
#include <assert.h>

void testMovie()
{
	Movie m1{ "Bohemian Rhapsody", "drama", 2018, 13400, "link1" };
	assert(m1.getTitle() == "Bohemian Rhapsody");
	assert(m1.getGenre() == "drama");
	assert(m1.getYear() == 2018);
	assert(m1.getNumberLikes() == 13400);
	assert(m1.getTrailer() == "link1");

	Movie m2{ "Moonlight", "drama", 2017, 12002, "link2" };
	m2.setNumberLikes(99999);
	m2.setYear(2018);
	m2.setTrailer("newLink");
	m2.setGenre("comedy");

	assert(m2.getGenre() == "comedy");
	assert(m2.getYear() == 2018);
	assert(m2.getNumberLikes() == 99999);
	assert(m2.getTrailer() == "newLink");
}

void testDynamicVector()
{
	Movie m1{ "Bohemian Rhapsody", "drama", 2018, 13400, "link1" };
	Movie m2{ "Moonlight", "drama", 2017, 12002, "link2" };
	Movie m3{ "Captain Marvel", "action", 2019, 15999, "link3" };
	Repository watchList;
	int success = 0;
	assert(watchList.getSize() == 0);
	success = watchList.addMovie(m1);
	assert(watchList.getSize() == 1);
	assert(success == 1);
	success = watchList.addMovie(m1);
	assert(watchList.getSize() == 1);
	assert(success == 0);
	watchList.addMovie(m2);
	assert(watchList.getSize() == 2);
	watchList.addMovie(m3);
	assert(watchList.getSize() == 3);
	success = watchList.deleteMovie("Moonlight");
	assert(success == 1);
	success = watchList.deleteMovie("Moonlight");
	assert(success == 0);
	assert(watchList.getSize() == 2);
	success = watchList.updateMovie("Captain Marvel", "action", 2099, 9999999, "newLink");
	assert(success == 1);
	success = watchList.updateMovie("Moonlight", "drama", 2099, 9999999, "newLink");
	assert(success == 0);
}

void testController()
{
	Repository watchList;
	Controller ctrl{ watchList };
	int success = ctrl.addMovie("Bohemian Rhapsody", "drama", 2018, 13400, "link1");
	assert(success == 1);
	success = ctrl.addMovie("Bohemian Rhapsody", "drama", 2018, 13400, "link1");
	assert(success == 0);
	success = ctrl.addMovie("", "drama", 2018, 13400, "link1");
	assert(success == -1);
	ctrl.addMovie("Bohemian Rhapsody", "drama", 2018, 13400, "link1");
	ctrl.addMovie("Moonlight", "drama", 2017, 12002, "link2");
	ctrl.addMovie("Captain Marvel", "action", 2019, 15999, "link3");
	success = ctrl.deleteMovie("Moonlight");
	assert(success == 1);
	success = ctrl.deleteMovie("Moonlight");
	assert(success == 0);
	success = ctrl.deleteMovie("");
	assert(success == -1);
	success = ctrl.updateMovie("Captain Marvel", "action", 2018, 9999, "newLink");
	assert(success == 1);
	success = ctrl.updateMovie("Moonlight", "drama", 2018, 9999, "newLink");
	assert(success == 0);
	success = ctrl.updateMovie("Captain Marveal", "action", 2018, 9999, "");
	assert(success == -1);
}