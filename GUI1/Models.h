#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Data
{
private:
	string id;
	string measurement;
	double imageClarityLevel;
	double  quantity;
	string photograph;

public:
	Data();

	Data(const string& id, const string& measurement, const double& imageClarityLevel, const double&  quantity, const string& photograph);

	string getId() const { return id; }
	string getMeasurement() const { return measurement; }
	double getImageClarityLevel() const { return imageClarityLevel; }
	double getQuantity() const { return quantity; }
	string getPhotograph() const { return photograph; }

	string toString();


	friend ostream& operator<<(ofstream& toPrint, Data &data);
	friend istream& operator>>(ifstream& toRead, Data &data);

};

