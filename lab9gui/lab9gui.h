#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lab9gui.h"
#include "gui.h"

class lab9gui : public QMainWindow
{
	Q_OBJECT

public:
	lab9gui(QWidget *parent = Q_NULLPTR);
	//lab9gui(Controller ctrl, QWidget *parent = Q_NULLPTR);
	//~lab9gui();


private:
	Ui::lab9guiClass ui;
};
