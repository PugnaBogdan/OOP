#pragma once
#include <exception>
using namespace std;

class repositoryException : public std::exception
{
private:
	string message;

public:
	repositoryException(const string& errorMessage) : message{ errorMessage } {}

	const char* what() const throw() override {
		return this->message.c_str();
	}
};

class dataException : public std::exception
{
private:
	string message;

public:
	dataException(const string& errorMessage) : message{ errorMessage } {}

	const char* what() const throw() override {
		return this->message.c_str();
	}
};

