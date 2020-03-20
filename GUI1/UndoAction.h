#pragma once
#include "Repository.h"

class UndoAction
{
public:

	virtual void executeUndo() = 0;
	virtual ~UndoAction() = default;
};

class UndoAdd : public UndoAction
{
private:
	Data addData;
	Repository& repo;

public:
	void executeUndo() override;
	~UndoAdd() = default;
	UndoAdd(Repository& repository, Data myData);
};

class UndoRemove : public UndoAction
{
private:
	Data addData;
	Repository& repo;

public:
	void executeUndo() override;
	~UndoRemove() = default;
	UndoRemove(Repository& repository, Data myData);
};

class UndoUpdate : public UndoAction
{
private:
	Data addData;
	Repository& repo;

public:
	void executeUndo() override;
	~UndoUpdate() = default;
	UndoUpdate(Repository& repository, Data myData);
};