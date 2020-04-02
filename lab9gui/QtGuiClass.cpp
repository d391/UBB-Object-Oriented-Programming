#include "QtGuiClass.h"



void QtGuiClass::update()
{
	this->model = new Model{ *this->ctrl.getUserFileRepo() };
	this->ui.tableView->setModel(this->model);
}

QtGuiClass::~QtGuiClass()
{
}
