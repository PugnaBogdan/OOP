#include "Repository.h"
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

void Repository::setFIle(const string& filePath)
{
	this->file = filePath;
}

void Repository::readFromFile()
{
	ifstream readFile(this->file);
	Data input;
	if (!readFile.is_open())
		return;
	while (readFile >> input)
		this->database.push_back(input);
	readFile.close();
}

void Repository::addToFile()
{
	ofstream putInFile(this->file);
	for (auto index : this->database)
		putInFile << index;
}
void Repository::addData(const Data& data)
{
	for (auto &itterator : this->database)
		if (itterator.getId().compare(data.getId()) == 0)
			throw repositoryException{ "Data already existing!\nSame id!" };
	this->database.push_back(data);
	this->addToFile();
}

void Repository::updateData(const Data& data)
{
	for (auto &itterator : this->database)
		if (itterator.getId().compare(data.getId()) == 0)
		{
			itterator = data;
			this->addToFile();
			return;
		}
	throw repositoryException{ "Data doesn't exist!\n" };

}

void Repository::deleteData(const string& id)
{
	for (auto itterator = this->database.begin(); itterator != this->database.end();)
	{
		if ((*itterator).getId().compare(id) == 0)
		{
			itterator = this->database.erase(itterator);
			this->addToFile();
			return;
		}
		else itterator++;
	}
	throw repositoryException{ "Data doesn't exist!\n" };

}

int Repository::getsize() const
{
	return this->database.size();
}

void RepositoryMyFile::setFIleMyList(const string & filePath)
{
	this->path = filePath;
}

void RepositoryMyFile::addData(const Data& data)
{
	for (auto &itterator : this->databaseMyFile)
		if (itterator.getId().compare(data.getId()) == 0)
			throw repositoryException{ "Data already existing!\nSame id!" };
	this->databaseMyFile.push_back(data);
	this->addDataToFIle();
}

int RepositoryMyFile::getsize() const
{
	return this->databaseMyFile.size();
}

void IsolatedRepository::updateData(const Data & data)
{
	if (data.getId().compare("isolatedId") != 0)
		throw dataException{ "isolatedTestCought" };
	throw dataException{ "isolatedTestNotCought" };
}

void CSVRepository::setRepository()
{
	this->databaseMyFileCSV = this->databaseMyFile;
}

void CSVRepository::addDataToFIle()
{
	ofstream putInFile(this->path);
	for (auto index : this->databaseMyFile)
		putInFile << index;
}

void HTMLRepository::setRepository()
{
	this->databaseMyFileHTML = this->databaseMyFile;
}

void HTMLRepository::addDataToFIle()
{
	ofstream file(this->path);
	if (!file.is_open()) return;

	file << "<!DOCTYPE html>";
	file << "<html>";
	file << "	<head>";
	file << "		<title>Task</title>";
	file << "	</head>";
	file << "	<body>";
	file << "		<table border=" << char(34) << "1" << char(34) << ">";
	file << "		<tr>";
	file << "			<td>Title</td>";
	file << "			<td>Type</td>";
	file << "			<td>Date</td>";
	file << "			<td>Number of repetitions</td>";
	file << "			<td>Vision</td>";
	file << "		</tr>";

	for (auto task : returnThis()) {
		file << "		<tr>";
		file << "			<td>" << task.getId() << "</td>";
		file << "			<td>" << task.getMeasurement() << "</td>";
		file << "			<td>" << task.getImageClarityLevel() << "</td>";
		file << "			<td>" << task.getQuantity() << "</td>";
		file << "			<td>" << task.getPhotograph() << "</td>";
		file << "		</tr>";
	}
	file << "		</table>";
	file << "	</body>";
	file << "</html>";
	file.close();
}
