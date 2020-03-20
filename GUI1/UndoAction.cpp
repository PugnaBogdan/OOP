#include "UndoAction.h"


void UndoAdd::executeUndo()
{
	this->repo.deleteData(this->addData.getId());
}

UndoAdd::UndoAdd(Repository & repository, Data myData) : repo(repository)
{
	this->addData = myData;
	//this->repo = r;
}

void UndoRemove::executeUndo()
{
	this->repo.addData(this->addData);
}

UndoRemove::UndoRemove(Repository & repository, Data myData) : repo(repository)
{
	this->addData = myData;
	//this->repo = r;
}

void UndoUpdate::executeUndo()
{
	this->repo.updateData(this->addData);
}

UndoUpdate::UndoUpdate(Repository & repository, Data myData) : repo(repository)
{
	this->addData = myData;
	//this->repo = r;
}
