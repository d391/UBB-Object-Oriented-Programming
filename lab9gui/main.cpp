#include "lab9gui.h"
#include "gui.h"
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>

#include "HTMLRepository.h"
#include "QtGuiClass.h"
#include <fstream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	std::string typeOfRepo;
	std::ifstream f("Configuration.txt");
	f >> typeOfRepo;
	if (typeOfRepo == "file")
	{
		FileRepository *repo = new FileRepository{ "Movies.txt" };
		Validator validator;
		FakeRepository *frepo = new HTMLRepository;
		Controller controller{ repo, validator, frepo };
		gui gui{ controller };
		QtGuiClass modelGui{ controller };
		modelGui.show();
		gui.show();
		return a.exec();
	}
	else if(typeOfRepo == "memory")
	{
		Repository *repo = new Repository;
		Validator validator;
		FakeRepository *frepo = new HTMLRepository;
		Controller controller{ repo, validator, frepo };
		gui gui{ controller };
		gui.show();
		return a.exec();
	}
	else
	{
		QMessageBox mes;
		mes.critical(0, "Error", "Incorect repo type in configuration file!");
		//return a.exec();
	}
}
