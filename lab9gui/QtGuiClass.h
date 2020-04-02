#pragma once

#include <QWidget>
#include "ui_QtGuiClass.h"
#include "Controller.h"
#include "Model.h"
#include "Observer.h"

class QtGuiClass : public QWidget, public Observer
{
	Q_OBJECT

public:
	QtGuiClass(Controller& _ctrl, QWidget *parent = Q_NULLPTR) : ctrl{ _ctrl }
	{
		ui.setupUi(this);
		this->model = new Model{ *this->ctrl.getUserFileRepo() };
		this->ui.tableView->setModel(this->model);
		this->ctrl.addObserver(this);
	};
	void update() override;
	~QtGuiClass();

private:
	Controller& ctrl;
	Model *model;
	Ui::QtGuiClass ui;
};
