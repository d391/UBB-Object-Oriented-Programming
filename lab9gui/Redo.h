#pragma once
#include "Movie.h"
#include "Repository.h"

class RedoAction
{
public:
	RedoAction() {};
	virtual void doRedo() {};
	~RedoAction() {};
};

class RedoAdd : public RedoAction
{
private:
	Movie movie;
	Repository& repo;
public:
	RedoAdd(Movie _mov, Repository& _repo) : movie{ _mov }, repo{ _repo }{};
	void doRedo()override { this->repo.addMovie(this->movie); };
	~RedoAdd() {};
};

class RedoUpdate : public RedoAction
{
private:
	Movie movie;
	Repository& repo;
public:
	RedoUpdate(Movie _mov, Repository &_repo) : movie{ _mov }, repo{ _repo }{};
	void doRedo()override { this->repo.updateMovie(this->movie); };
	~RedoUpdate() {};
};

class RedoDelete : public RedoAction
{
private:
	Movie movie;
	Repository& repo;
public:
	RedoDelete(Movie _mov, Repository &_repo) : movie{ _mov }, repo{ _repo }{};
	void doRedo()override { this->repo.deleteMovie(this->movie); };
	~RedoDelete() {};
};