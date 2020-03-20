#pragma once
#include "Models.h"
#include <vector>
#include <fstream>
#include "Exceptions.h"
class Repository
{
private:
	vector<Data> database;
	string file;

public:

	Repository() {}
	virtual void setFIle(const string& filePath);
	virtual void addData(const Data& data);
	virtual void updateData(const Data& data);
	void deleteData(const string& id);
	virtual vector<Data> returnThis() const { return database; }
	//void returnAll();
	//Data* returnThis() const;
	//DynamicVector* xx();
	virtual int getsize() const;
	void readFromFile();
	virtual void addToFile();
	//vector<string> tokenize(string line);
};

class RepositoryMyFile : public Repository
{
protected:
	vector<Data> databaseMyFile;
	string path;
public:

	RepositoryMyFile() {}
	void setFIleMyList(const string& filePath);
	virtual void addData(const Data& data);
	vector<Data> returnThis() const { return databaseMyFile; }
	//Data* returnThis() const;
	//DynamicVector* xx();
	virtual int getsize() const;
	virtual void addDataToFIle() = 0;
};

class CSVRepository : public RepositoryMyFile
{
private:
	vector<Data> databaseMyFileCSV;
public:
	void setRepository();
	void addDataToFIle() override;
};

class HTMLRepository : public RepositoryMyFile
{
private:
	vector<Data> databaseMyFileHTML;
public:
	void setRepository();
	void addDataToFIle() override;
};

class IsolatedRepository :public Repository
{
private:

public:
	void updateData(const Data& data);
};