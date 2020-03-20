#include "Service.h"

void Service::undoAction()
{
	if (this->Undolist.size()  == 0)
	{
		throw exception("no more undos");
		return;
	}
	this->Undolist[index1--]->executeUndo();
	//this->Undolist.pop_back();
	index2--;
	
}

void Service::RedoAction()
{
	if (this->Redolist.size() == 0)
	{
		throw exception("no more redos");
		return;
	}
	this->Redolist[++index2]->executeRedo();
	//this->Redolist.pop_back();
	index1++;
}

Data Service::getData(const string & id)
{
	for (auto i : this->getALL())
		if (i.getId().compare(id) == 0)
			return i;
}

void Service::addDataToRepository(const string& id, const string& measurement, const double& imageClarityLevel, const double&  quantity, const string& photograph)
{
	Data data{ id, measurement, imageClarityLevel, quantity, photograph };
	this->repository.addData(data);
	unique_ptr<UndoAdd> pointer = make_unique<UndoAdd>(this->repository, data);
	this->Undolist.push_back(move(pointer));
	index1++;
	unique_ptr<RedoAdd> pointer2 = make_unique<RedoAdd>(this->repository, data);
	this->Redolist.push_back(move(pointer2));
	index2++;
}

vector<Data> Service::getALL() const
{
	return this->repository.returnThis();
}

void Service::updateDataToRepository(const string& id, const string& measurement, const double& imageClarityLevel, const double&  quantity, const string& photograph)
{
	Data data{ id, measurement, imageClarityLevel, quantity, photograph };
	Data data2;
	for (auto i : this->getALL())
		if (i.getId().compare(id) == 0)
		{
			data2 = i;
			break;
		}
	this->repository.updateData(data);
	unique_ptr<UndoUpdate> pointer = make_unique<UndoUpdate>(this->repository, data2);
	this->Undolist.push_back(move(pointer));
	index1++;
	unique_ptr<RedoUpdate> pointer2 = make_unique<RedoUpdate>(this->repository, data);
	this->Redolist.push_back(move(pointer2));
	index2++;
}

void Service::deleteDatatoRepository(const string& id)
{
	Data data;
	for (auto i : this->getALL())
		if (i.getId().compare(id) == 0)
		{
			data = i;
			break;
		}
	this->repository.deleteData(id);
	unique_ptr<UndoRemove> pointer1 = make_unique<UndoRemove>(this->repository, data);
	this->Undolist.push_back(move(pointer1));
	index1++;

	unique_ptr<RedoRemove> pointer2 = make_unique<RedoRemove>(this->repository, data);
	this->Redolist.push_back(move(pointer2));
	index2++;
}

int Service::getthis() const
{

	return this->repository.getsize();
}

void Service::saveService(string id)
{
	vector<Data> vector = this->repository.returnThis();
	for (auto itterator : vector)
		if (itterator.getId().compare(id) == 0)
			this->myList->addData(itterator);
}

vector<Data> Service::getALLmyList() const
{
	return this->myList->returnThis();
}

int Service::getthisMyList() const
{
	return this->myList->getsize();
}

void Service::setFileService(const string & filePath)
{
	this->repository.setFIle(filePath);
}

void Service::readFileService()
{
	this->repository.readFromFile();
}

void Service::setMyListType(string myListTye)
{
	string fileType;
	fileType = myListTye.substr(myListTye.size() - 4, 4);


	if (fileType == ".csv") {
		CSVRepository* newRepository = new CSVRepository();
		this->myList = newRepository;
		this->myList->setFIleMyList(myListTye);
	}
	else {
		if (fileType == "html") {
			HTMLRepository* newRepository = new HTMLRepository();
			this->myList = newRepository;
			this->myList->setFIleMyList(myListTye);
		}

	}
}

