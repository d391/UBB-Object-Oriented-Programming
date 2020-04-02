#pragma once
#include "tests.h"
#include "ui.h"
#include <iostream>
#include <string>
#include "HTMLRepository.h"

int main()
{
	//testAll();

	FileRepository fileRepo{};
	Validator validator;
	FakeRepository *frepo = new HTMLRepository;
	Controller controller{ fileRepo, validator, frepo };
	ui ui{ controller };
	ui.run();
	return 0;
}