#include "RedoAction.h"


void RedoAdd::executeRedo()
{
	this->repo.addData(this->addData);
}

RedoAdd::RedoAdd(Repository & repository, Data myData) : repo(repository)
{
	this->addData = myData;
	this->repo = repository;
}

void RedoRemove::executeRedo()
{
	this->repo.deleteData(this->addData.getId());
}

RedoRemove::RedoRemove(Repository & repository, Data myData) : repo(repository)
{
	this->addData = myData;
	this->repo = repository;
}

void RedoUpdate::executeRedo()
{
	this->repo.updateData(this->addData);
}

RedoUpdate::RedoUpdate(Repository & repository, Data myData) : repo(repository)
{
	this->addData = myData;
	this->repo = repository;
}
