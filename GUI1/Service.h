#pragma once
#include "UndoAction.h"
#include "RedoAction.h"
class Service
{
private:
	Repository repository;
	RepositoryMyFile* myList;
	string myListType;
	int index1=-1, index2 = -1;
	std::vector<std::unique_ptr<UndoAction>> Undolist;
	std::vector<std::unique_ptr<RedoAction>> Redolist;


public:
	Service(Repository& currentRepository, RepositoryMyFile* myListRepository) : repository{ currentRepository }, myList{ myListRepository } {}

	//Repository& getRepo() const { return repository; }
	void undoAction();
	void RedoAction();
	Data getData(const string& id);
	void addDataToRepository(const string& id, const string& measurement, const double& imageClarityLevel, const double&  quantity, const string& photograph);
	void updateDataToRepository(const string& id, const string& measurement, const double& imageClarityLevel, const double&  quantity, const string& photograph);
	void deleteDatatoRepository(const string& id);
	vector<Data> getALL() const;
	int getthis() const;
	virtual void saveService(string id);
	vector<Data> getALLmyList() const;
	int getthisMyList() const;
	void setFileService(const string& filePath);
	void readFileService();
	void setMyListType(string myListTye);
};
