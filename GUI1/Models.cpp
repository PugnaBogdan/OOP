#include "Models.h"



Data::Data() : id(""), measurement(""), imageClarityLevel(0), quantity(0), photograph("") {}

Data::Data(const string& id, const string& measurement, const double& imageClarityLevel, const double&  quantity, const string& photograph)
{
	this->id = id;
	this->measurement = measurement;
	this->imageClarityLevel = imageClarityLevel;
	this->quantity = quantity;
	this->photograph = photograph;
}

string Data::toString()
{
	return id+","+measurement+","+to_string(imageClarityLevel)+","+to_string(quantity)+","+photograph;
}

vector<string> split(string stringToSplit, char delimiter)
{
	vector <string> result;
	stringstream splitingString(stringToSplit);
	string token;
	while (getline(splitingString, token, delimiter))
		result.push_back(token);

	return result;
}

ostream & operator<<(ofstream & toPrint, Data & data)
{
	toPrint << data.getId() << "," << data.getMeasurement() << "," << data.getImageClarityLevel() << "," << data.getQuantity() << "," << data.getPhotograph() << "\n";
	return toPrint;
}

istream & operator>>(ifstream & readFromFile, Data & data)
{
	string line;
	getline(readFromFile, line);

	vector<string> parameters = split(line, ',');
	if (parameters.size() != 5)
		return readFromFile;
	data.id = parameters[0];
	data.measurement = parameters[1];
	data.imageClarityLevel = stod(parameters[2]);
	data.quantity = stod(parameters[3]);
	data.photograph = parameters[4];

	return readFromFile;
}

