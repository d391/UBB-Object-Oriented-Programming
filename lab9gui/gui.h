#pragma once
#include "Controller.h"

#include <QtWidgets/QMainWindow>
#include <QtCore/QStringListModel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <vector>
#include <numeric>
#include <algorithm>
#include <QMessageBox>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QList>
#include <QListWidget>
#include <QLineEdit>
#include <QShortcut>

#include <QtGuiClass.h>
#include "Observer.h"

//#include "Model.h"

class gui : public QWidget, public Observer
{
	Q_OBJECT
private:
	Controller& ctrl;
	std::vector<Movie> currentWatchList;

	//QtGuiClass* userWindow;
	//Model model;

	QWidget *userWidget;
	QWidget *adminWidget;
	
	QListWidget *adminWidgetList;
	QListWidget *userWidgetList;

	QLineEdit *titleTextBox;
	QLineEdit *genreTextBox;
	QLineEdit *yearTextBox;
	QLineEdit *numberLikesTextBox;
	QLineEdit *trailerTextBox;


	// buttons
	QPushButton *addButton;
	QPushButton *deleteButton;
	QPushButton *updateButton;
	QPushButton *addToWatchListButton;
	QPushButton *playButton;
	QPushButton *nextButton;
	QPushButton *filterButton;
	QPushButton *modeAButton;
	QPushButton *modeBButton;
	QPushButton *undoButton;
	QPushButton *redoButton;

	QShortcut *undoShortcut;
	QShortcut *redoShortcut;

	void populateList();
	void populateWidgetList();
	void populateWidgetUserList();
	void connectSignalsAndSlots();

	void addButtonHandler();
	void deleteButtonHandler();
	void updateButtonHandler();
	void filterButtonHandler();
	void addToWatchListHandler();
	void nextButtonHandler();
	void playButtonHandler();
	void modeAButtonHandler();
	void modeBButtonHandler();
	void undoButtonHandler();
	void redoButtonHandler();
	void update()override { this->populateWidgetUserList(); };

signals:
	void addMovieSignal(const std::string movieTitle, const std::string movieGenre, const int movieYear, const int movieNumberLikes, const std::string movieTrailer);
	void deleteMovieSignal(const std::string movieTitle);
	void updateMovieSignal(const std::string movieTitle, const std::string movieGenre, const int movieYear, const int movieNumberLikes, const std::string movieTrailer);
	void filterMoviesSignal(const std::string genre, const int numberLikes);
	void addToWatchListSignal(const std::string title);
	void nextSignal();
	void playSignal();
	void modeASignal();
	void modeBSignal();

public slots:
	void addMovieSlot(const std::string movieTitle, const std::string movieGenre, const int movieYear, const int movieNumberLikes, const std::string movieTrailer);
	void deleteMovieSlot(const std::string movieTitle);
	void updateMovieSlot(const std::string movieTitle, const std::string movieGenre, const int movieYear, const int movieNumberLikes, const std::string movieTrailer);
	void filterMoviesSlot(const std::string genre, const int numberLikes);
	void addToWatchListSlot(const std::string title);
	void nextSlot();
	void modeASlot();
	void modeBSlot();


public:
	gui(Controller& _ctrl, QWidget * parent = Q_NULLPTR) : ctrl{ _ctrl }, QWidget{ parent } 
	{ 
		this->setGui(); this->connectSignalsAndSlots(); this->populateList(); 
		this->currentWatchList = this->ctrl.getAllElements(); 
		this->populateWidgetList();

	};
	~gui();
private:
	void setGui();
};
