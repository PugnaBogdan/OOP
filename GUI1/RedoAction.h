#pragma once
#include "Repository.h"
class RedoAction
{
public:

	virtual void executeRedo() = 0;
	virtual ~RedoAction() = default;
};

class RedoAdd : public RedoAction
{
private:
	Data addData;
	Repository& repo;

public:
	void executeRedo() override;
	~RedoAdd() = default;
	RedoAdd(Repository& repository, Data myData);
};

class RedoRemove : public RedoAction
{
private:
	Data addData;
	Repository& repo;

public:
	void executeRedo() override;
	~RedoRemove() = default;
	RedoRemove(Repository& repository, Data myData);
};

class RedoUpdate : public RedoAction
{
private:
	Data addData;
	Repository& repo;

public:
	void executeRedo() override;
	~RedoUpdate() = default;
	RedoUpdate(Repository& repository, Data myData);
};