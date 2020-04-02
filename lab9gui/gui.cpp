#include "gui.h"
#include "Exception.h"
#include <QDesktopServices>
#include <QUrl>

void gui::setGui()
{
	//this->userWindow = new QtGuiClass{ this->ctrl };
	this->ctrl.addObserver(this);
	//this->ctrl.addObserver(this->userWindow);

	QVBoxLayout *mainLayout = new QVBoxLayout{ this };

	this->adminWidget = new QWidget{};
	this->adminWidgetList = new QListWidget;

	QVBoxLayout *adminLayout = new QVBoxLayout{ adminWidget };
	QLabel *adminLabel = new QLabel{ "Admin watchlist" };
	adminLabel->setBuddy(this->adminWidgetList);
	mainLayout->addWidget(adminWidgetList);
	
	QWidget *movieDataWidget = new QWidget{};
	QFormLayout *movieDataForm = new QFormLayout{ movieDataWidget };

	QLabel *titleLabel = new QLabel{ "Title: " };
	this->titleTextBox = new QLineEdit;
	titleLabel->setBuddy(this->titleTextBox);

	QLabel *genreLabel = new QLabel{ "Genre: " };
	this->genreTextBox = new QLineEdit;
	genreLabel->setBuddy(this->genreTextBox);

	QLabel *yearLabel = new QLabel{ "Year: " };
	this->yearTextBox = new QLineEdit;
	yearLabel->setBuddy(this->yearTextBox);

	QLabel *numberLikesLabel = new QLabel{ "Number of likes: " };
	this->numberLikesTextBox = new QLineEdit;
	numberLikesLabel->setBuddy(this->numberLikesTextBox);

	QLabel *trailerLabel = new QLabel{ "Trailer link: " };
	this->trailerTextBox = new QLineEdit;
	trailerLabel->setBuddy(this->trailerTextBox);

	movieDataForm->addRow(titleLabel, this->titleTextBox);
	movieDataForm->addRow(genreLabel, this->genreTextBox);
	movieDataForm->addRow(yearLabel, this->yearTextBox);
	movieDataForm->addRow(numberLikesLabel, this->numberLikesTextBox);
	movieDataForm->addRow(trailerLabel, this->trailerTextBox);

	adminLayout->addWidget(movieDataWidget);

	QWidget *adminButtonsWidget = new QWidget{};
	QHBoxLayout *adminButtonsLayout = new QHBoxLayout{ adminButtonsWidget };
	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };
	this->filterButton = new QPushButton{ "Filter" };
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };

	adminButtonsLayout->addWidget(this->addButton);
	adminButtonsLayout->addWidget(this->deleteButton);
	adminButtonsLayout->addWidget(this->updateButton);
	adminButtonsLayout->addWidget(this->filterButton);
	adminButtonsLayout->addWidget(this->undoButton);
	adminButtonsLayout->addWidget(this->redoButton);

	adminLayout->addWidget(adminButtonsWidget);

	mainLayout->addWidget(adminWidget);

	QWidget *addToPlaylistWidget = new QWidget{};
	QVBoxLayout *addToPlaylistLayout = new QVBoxLayout{ addToPlaylistWidget };
	this->addToWatchListButton = new QPushButton{ ">" };
	this->modeAButton = new QPushButton{ "Mode A" };
	this->modeBButton = new QPushButton{ "Mode B" };
	addToPlaylistLayout->addWidget(this->modeAButton);
	addToPlaylistLayout->addWidget(addToWatchListButton);
	addToPlaylistLayout->addWidget(this->modeBButton);

	mainLayout->addWidget(addToPlaylistWidget);

	this->userWidget = new QWidget{};
	QVBoxLayout *userLayout = new QVBoxLayout{ userWidget };
	this->userWidgetList = new QListWidget{};
	
	userLayout->addWidget(new QLabel{ "User watchlist: " });
	userLayout->addWidget(this->userWidgetList);

	QWidget *userButtonsWidget = new QWidget{};
	QHBoxLayout *userButtonsLayout = new QHBoxLayout{ userButtonsWidget };
	this->playButton = new QPushButton{ "Play" };
	this->nextButton = new QPushButton{ "Next" };

	userButtonsLayout->addWidget(this->playButton);
	userButtonsLayout->addWidget(this->nextButton);

	userLayout->addWidget(userButtonsWidget);

	mainLayout->addWidget(userWidget);

	userWidget->hide();
	adminWidget->hide();
	this->addToWatchListButton->hide();
	this->adminWidgetList->hide();

	this->undoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z), this->undoButton);
	this->redoShortcut = new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Y), this->redoButton);
}

void gui::populateList()
{
	
}

void gui::populateWidgetList()
{
	this->adminWidgetList->clear();
	int index = 0;
	for (Movie mov : this->currentWatchList)
	{
		if (index != this->ctrl.getIndex())
		{
			QString itemInList = QString::fromStdString(mov.movieString());
			QFont f{ "Comic Sans MS", 9};
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			item->setFont(f);
			this->adminWidgetList->addItem(item);
		}
		else
		{
			QString itemInList = QString::fromStdString(mov.movieString());
			QFont f{ "Comic Sans MS", 9 , -1, true };
			QListWidgetItem* item = new QListWidgetItem{ itemInList };
			item->setFont(f);
			this->adminWidgetList->addItem(item);
		}
		index++;
	}
		
}

void gui::populateWidgetUserList()
{
	this->userWidgetList->clear();
	for (Movie mov : this->ctrl.getUserWatchList())
	{
		QString itemInList = QString::fromStdString(mov.movieString());
		QFont f{ "Comic Sans MS", 9 };
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		item->setFont(f);
		this->userWidgetList->addItem(item);
	}
}

void gui::connectSignalsAndSlots()
{
	QObject::connect(this->addButton, &QPushButton::clicked, this, &gui::addButtonHandler);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &gui::deleteButtonHandler);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &gui::updateButtonHandler);
	QObject::connect(this->filterButton, &QPushButton::clicked, this, &gui::filterButtonHandler);
	QObject::connect(this->addToWatchListButton, &QPushButton::clicked, this, &gui::addToWatchListHandler);
	QObject::connect(this->nextButton, &QPushButton::clicked, this, &gui::nextButtonHandler);
	QObject::connect(this->playButton, &QPushButton::clicked, this, &gui::playButtonHandler);
	QObject::connect(this->modeAButton, &QPushButton::clicked, this, &gui::modeAButtonHandler);
	QObject::connect(this->modeBButton, &QPushButton::clicked, this, &gui::modeBButtonHandler);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &gui::undoButtonHandler);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &gui::redoButtonHandler);

	QObject::connect(this, SIGNAL(addMovieSignal(const std::string& , const std::string&, const int& , const int& , const std::string& )), this, SLOT(addMovieSlot(const std::string& , const std::string& , const int& , const int& , const std::string& )));
	QObject::connect(this, SIGNAL(deleteMovieSignal(const std::string&)), this, SLOT(deleteMovieSlot(const std::string&)));
	QObject::connect(this, SIGNAL(updateMovieSignal(const std::string&, const std::string&, const int&, const int&, const std::string&)), this, SLOT(updateMovieSlot(const std::string&, const std::string&, const int&, const int&, const std::string&)));
	QObject::connect(this, SIGNAL(filterMoviesSignal(const std::string&, const int&)), this, SLOT(filterMoviesSlot(const std::string&, const int&)));
	QObject::connect(this, SIGNAL(nextSignal()), this, SLOT(nextSlot()));
	QObject::connect(this, SIGNAL(addToWatchListSignal(const std::string&)), this, SLOT(addToWatchListSlot(const std::string&)));
	QObject::connect(this, SIGNAL(modeASignal()), this, SLOT(modeASlot()));
	QObject::connect(this, SIGNAL(modeBSignal()), this, SLOT(modeBSlot()));

	QObject::connect(this->undoShortcut, SIGNAL(activated()), this->undoButton, SLOT(animateClick()));
	QObject::connect(this->redoShortcut, SIGNAL(activated()), this->redoButton, SLOT(animateClick()));
}



void gui::addButtonHandler()
{
	QString movieTitle = this->titleTextBox->text();
	QString movieGenre = this->genreTextBox->text();
	QString movieYear = this->yearTextBox->text();
	QString movieNumberLikes = this->numberLikesTextBox->text();
	QString movieTrailer = this->trailerTextBox->text();

	if (movieTitle != "" && movieGenre != "" && movieYear != "" && movieNumberLikes != "" && movieTrailer != "")
		emit addMovieSignal(movieTitle.toStdString(), movieGenre.toStdString(), stoi(movieYear.toStdString()), stoi(movieNumberLikes.toStdString()), movieTrailer.toStdString());
	else
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", "Empty fields! Please introduce all data!");
	}
}

void gui::deleteButtonHandler()
{
	QString movieTitle = this->titleTextBox->text();
	if (movieTitle != "")
		emit deleteMovieSignal(movieTitle.toStdString());
	else
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", "Empty fields! Please introduce all data!");
	}
}

void gui::updateButtonHandler()
{
	QString movieTitle = this->titleTextBox->text();
	QString movieGenre = this->genreTextBox->text();
	QString movieYear = this->yearTextBox->text();
	QString movieNumberLikes = this->numberLikesTextBox->text();
	QString movieTrailer = this->trailerTextBox->text();

	if(movieTitle!="" && movieGenre!="" && movieYear!="" && movieNumberLikes!="" && movieTrailer!="")
		emit updateMovieSignal(movieTitle.toStdString(), movieGenre.toStdString(), stoi(movieYear.toStdString()), stoi(movieNumberLikes.toStdString()), movieTrailer.toStdString());
	else
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", "Empty fields! Please introduce all data!");
	}
}

void gui::filterButtonHandler()
{
	QString movieGenre = this->genreTextBox->text();
	QString movieNumberLikes = this->numberLikesTextBox->text();

	if(movieGenre.toStdString() != "" && movieNumberLikes!="")
		emit filterMoviesSignal(movieGenre.toStdString(), stoi(movieNumberLikes.toStdString()));
	else
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", "Empty fields! Please introduce all data!");
	}
}

void gui::addToWatchListHandler()
{
	emit addToWatchListSignal(this->currentWatchList[this->ctrl.getIndex()].getTitle());
}

void gui::nextButtonHandler()
{
	emit nextSignal();
}

void gui::playButtonHandler()
{
	QString link = QString::fromStdString(this->currentWatchList[this->ctrl.getIndex()].getTrailer());
	QDesktopServices::openUrl(QUrl(link));
}

void gui::modeAButtonHandler()
{
	emit modeASignal();
}

void gui::modeBButtonHandler()
{
	emit modeBSignal();
}

void gui::undoButtonHandler()
{
	try
	{
		this->ctrl.undo();
		this->currentWatchList = this->ctrl.getAllElements();
		this->populateWidgetList();
	}
	catch (Exception& e)
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", e.what());
	}
}

void gui::redoButtonHandler()
{
	try
	{
		this->ctrl.redo();
		this->currentWatchList = this->ctrl.getAllElements();
		this->populateWidgetList();
	}
	catch (Exception& e)
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", e.what());
	}
}

void gui::addMovieSlot(const std::string movieTitle, const std::string movieGenre, const int movieYear, const int movieNumberLikes, const std::string movieTrailer)
{
	try
	{
		this->ctrl.addMovie(movieTitle, movieGenre, movieYear, movieNumberLikes, movieTrailer);
		this->currentWatchList = this->ctrl.getAllElements();
		this->populateWidgetList();
	}
	catch (Exception& e)
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", e.what());
	}
}

void gui::deleteMovieSlot(const std::string movieTitle)
{
	try
	{
		this->ctrl.deleteMovie(movieTitle);
		this->currentWatchList = this->ctrl.getAllElements();
		this->populateWidgetList();
	}
	catch (Exception& e)
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", e.what());
	}
}

void gui::updateMovieSlot(const std::string movieTitle, const std::string movieGenre, const int movieYear, const int movieNumberLikes, const std::string movieTrailer)
{
	try
	{
		this->ctrl.updateMovie(movieTitle, movieGenre, movieYear, movieNumberLikes, movieTrailer);
		this->currentWatchList = this->ctrl.getAllElements();
		this->populateWidgetList();
	}
	catch (Exception& e)
	{
		QMessageBox errorMessage;
		errorMessage.critical(0, "Error", e.what());
	}
}

void gui::filterMoviesSlot(const std::string genre, const int numberLikes)
{
	this->currentWatchList = this->ctrl.getGenreLikesList(genre, numberLikes);
	this->ctrl.reSetIndex();
	this->populateWidgetList();
}

void gui::addToWatchListSlot(const std::string title)
{
	this->ctrl.addToUserWatchList(title);
	//this->populateWidgetUserList();
}

void gui::nextSlot()
{
	this->ctrl.next(this->currentWatchList.size());
	this->populateWidgetList();
}

void gui::modeASlot()
{
	this->ctrl.reSetIndex();
	this->adminWidget->show();
	this->adminWidgetList->show();
	this->userWidget->hide();
	this->addToWatchListButton->hide();
}

void gui::modeBSlot()
{
	this->adminWidget->hide();
	this->adminWidgetList->show();
	this->userWidget->show();
	this->addToWatchListButton->show();
	//this->userWindow->show();
}

/*void gui::keyPressEvent(QKeyEvent *_event)
{
	
}*/

gui::~gui()
{
}
