#pragma once
#include "Movie.h"
#include "Repository.h"

class UndoAction
{
public:
	UndoAction();
	virtual void doUndo() {};
	~UndoAction();
};

class UndoAdd : public UndoAction
{
private:
	Movie movie;
	Repository& repo;
public:
	UndoAdd(Movie _mov, Repository& _repo) : movie{ _mov }, repo{ _repo }{};
	void doUndo()override { this->repo.deleteMovie(this->movie); };
	~UndoAdd() {};
};

class UndoUpdate : public UndoAction
{
private:
	Movie movie;
	Repository& repo;
public:
	UndoUpdate(Movie _mov, Repository &_repo): movie{ _mov }, repo{ _repo }{};
	void doUndo()override { this->repo.updateMovie(this->movie); };
	~UndoUpdate() {};
};

class UndoDelete : public UndoAction
{
private:
	Movie movie;
	Repository& repo;
public:
	UndoDelete(Movie _mov, Repository &_repo) : movie{ _mov }, repo{ _repo }{};
	void doUndo()override { this->repo.addMovie(this->movie); };
	~UndoDelete() {};
};