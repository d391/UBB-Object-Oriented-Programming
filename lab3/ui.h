#pragma once
#include "Controller.h"

typedef struct
{
	Controller* controller;
}UI;

UI *createUI(Controller* controller);
void destroyUI(UI *ui);

void startUI(UI *ui);