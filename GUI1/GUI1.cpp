#pragma once
#include "GUI1.h"
#include <qmessagebox.h>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <exception>

GUI1::GUI1(Service * service, QWidget *parent)
	: QWidget(parent)
{

	//ui.setupUi(this);
	this->service = service;
	this->initialize();
	
	//this->run();
}

void GUI1::run()
{

	
	myLittleModel = new MyModel{ service };
	newTableWindow = new newTableClass{ myLittleModel };
	newTableWindow2 = new newTableClass{ myLittleModel };

	labelFile->deleteLater();
	labelMyFile->deleteLater();
	labelStartingMode->deleteLater();
	lineEditFile->deleteLater();
	lineEditMyFile->deleteLater();
	lineEditStartingMode->deleteLater();
	buttonStart->deleteLater();
	//this->files();	
	layoutHorizontalGeneral = new QHBoxLayout{ this };

	//first vertical layout
	firstVerticalLayout = new QVBoxLayout{};

	labelHeaderArchives = new QLabel("All Archives");
	firstVerticalLayout->addWidget(labelHeaderArchives);

	listArchives = new QListWidget{};
	firstVerticalLayout->addWidget(listArchives);

	formLayoutData = new QFormLayout{};
	labelId = new QLabel{ "&Id:" };
	lineEditId = new QLineEdit{};
	labelId->setBuddy(lineEditId);
	formLayoutData->addRow(labelId, lineEditId);

	labelMeasurement = new QLabel{ "&Measurement:" };
	lineEditMeasurement = new QLineEdit{};
	labelMeasurement->setBuddy(lineEditMeasurement);
	formLayoutData->addRow(labelMeasurement, lineEditMeasurement);

	labelImageLevel = new QLabel{ "&ImageClarityLevel:" };
	lineEditImageLevel = new QLineEdit{};
	labelImageLevel->setBuddy(lineEditImageLevel);
	formLayoutData->addRow(labelImageLevel, lineEditImageLevel);

	labelQuantity = new QLabel{ "&Quantity:" };
	lineEditQuantity = new QLineEdit{};
	labelQuantity->setBuddy(lineEditQuantity);
	formLayoutData->addRow(labelQuantity, lineEditQuantity);

	labelPhotograph = new QLabel{ "&Photograph:" };
	lineEditPhotograph = new QLineEdit{};
	labelPhotograph->setBuddy(lineEditPhotograph);
	formLayoutData->addRow(labelPhotograph, lineEditPhotograph);

	firstVerticalLayout->addLayout(formLayoutData);

	ArchivesButtonsHorizontalLayout = new QHBoxLayout{};
	buttonAdd = new QPushButton{ "&Add" };
	buttonRemove = new QPushButton{ "&Remove" };
	buttonUpdate = new QPushButton{ "&Update" };

	ArchivesButtonsHorizontalLayout->addWidget(buttonAdd);
	ArchivesButtonsHorizontalLayout->addWidget(buttonRemove);
	ArchivesButtonsHorizontalLayout->addWidget(buttonUpdate);

	firstVerticalLayout->addLayout(ArchivesButtonsHorizontalLayout);

	//second vertical layout
	secondVerticalLayout = new QVBoxLayout{};
	buttonAdministrator = new QPushButton{ "&Administrator" };
	buttonUser = new QPushButton{ "&User" };
	undo = new QPushButton{ "&Undo" };
	redo = new QPushButton{ "&Redo" };
	secondVerticalLayout->addWidget(buttonAdministrator);
	secondVerticalLayout->addWidget(buttonUser);
	secondVerticalLayout->addWidget(undo);
	secondVerticalLayout->addWidget(redo);

	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this, SLOT(Undo()));
	new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this, SLOT(Redo()));

	//third vertical layout
	thirdVerticalLayout = new QVBoxLayout{};

	labelHeaderShoppingBasket = new QLabel("My Files");
	thirdVerticalLayout->addWidget(labelHeaderShoppingBasket);

	listMyFile = new QListWidget{};
	thirdVerticalLayout->addWidget(listMyFile);

	MyFileButtonsHorizontalLayout = new QHBoxLayout{};
	buttonSave = new QPushButton{ "&Save" };
	buttonNext = new QPushButton{ "&Next" };
	buttonFilter = new QPushButton{ "&Filter" };
	myList = new QPushButton{ "&My List" };


	MyFileButtonsHorizontalLayout->addWidget(buttonSave);
	MyFileButtonsHorizontalLayout->addWidget(buttonNext);
	MyFileButtonsHorizontalLayout->addWidget(buttonFilter);
	MyFileButtonsHorizontalLayout->addWidget(myList);
	//shoppingBasketButtonsHorizontalLayout->addWidget(buttonChart);

	thirdVerticalLayout->addLayout(MyFileButtonsHorizontalLayout);

	layoutHorizontalGeneral->addLayout(firstVerticalLayout);
	layoutHorizontalGeneral->addLayout(secondVerticalLayout);
	layoutHorizontalGeneral->addLayout(thirdVerticalLayout);

	if (mode.compare("A") == 0)
		this->administratorMode();
	else if (mode.compare("B") == 0)
		this->userMode();

	QObject::connect(myList, &QPushButton::clicked, this, &GUI1::myNewTableFunction);

	QObject::connect(buttonAdministrator, &QPushButton::clicked, this, &GUI1::administratorMode);
	QObject::connect(buttonUser, &QPushButton::clicked, this, &GUI1::userMode);

	this->listPopulate();
	QObject::connect(buttonAdd, &QPushButton::clicked, this, &GUI1::add);
	

	QObject::connect(buttonRemove, &QPushButton::clicked, this, &GUI1::remove);
	
	
	QObject::connect(buttonUpdate, &QPushButton::clicked, this, &GUI1::update);
	QObject::connect(buttonNext, &QPushButton::clicked, this, &GUI1::next);
	QObject::connect(buttonSave, &QPushButton::clicked, this, &GUI1::save);
	
	QObject::connect(buttonFilter, &QPushButton::clicked, this, &GUI1::filter);
	QObject::connect(undo, &QPushButton::clicked, this, &GUI1::Undo);
	QObject::connect(redo, &QPushButton::clicked, this, &GUI1::Redo);

	
}


void GUI1::initialize()
{
	startLayout = new QHBoxLayout{ this };
	startForm = new QFormLayout{};
	labelFile = new QLabel{ "&FileLocation:" };
	lineEditFile = new QLineEdit{};
	labelFile->setBuddy(lineEditFile);
	startForm->addRow(labelFile, lineEditFile);
	labelMyFile = new QLabel{ "&MyFileLocation:" };
	lineEditMyFile = new QLineEdit{};
	labelMyFile->setBuddy(lineEditMyFile);
	startForm->addRow(labelMyFile, lineEditMyFile);
	labelStartingMode = new QLabel{ "&StartingMode:" };
	lineEditStartingMode = new QLineEdit{};
	labelStartingMode->setBuddy(lineEditStartingMode);
	startForm->addRow(labelStartingMode, lineEditStartingMode);

	buttonStart = new QPushButton{ "&Start" };
	startLayout->addLayout(startForm);
	startLayout->addWidget(buttonStart);

	QObject::connect(buttonStart, &QPushButton::clicked, this, &GUI1::initialize2);
	startLayout->deleteLater();

}

void GUI1::initialize2()
{
	if (lineEditFile->text().compare("") == 0 || lineEditMyFile->text().compare("") == 0 || lineEditStartingMode->text().compare("") == 0)
	{
		QMessageBox::warning(this, "Warning", "All lines must be filled");
		return;
	}
	else {
		if (lineEditStartingMode->text().compare("A")==0)
			mode = "A";
		else if (lineEditStartingMode->text().compare("B")==0)
			mode = "B";
		else
		{
			QMessageBox::warning(this, "Warning", "Wrong mode: chhose A or B");
			return;
		}
		string filePath = lineEditFile->text().toStdString();
		string myfilePath = lineEditMyFile->text().toStdString();
		this->service->setFileService(filePath);
		this->service->setMyListType(myfilePath);
		this->service->readFileService();
		this->run();
	}
	
		
}

void GUI1::administratorMode()
{
	buttonSave->setEnabled(false);
	buttonNext->setEnabled(false);
	buttonAdd->setEnabled(true);
	buttonRemove->setEnabled(true);
	buttonUpdate->setEnabled(true);
	buttonFilter->setEnabled(false);
	myList->setEnabled(false);
}

void GUI1::userMode()
{
	buttonAdd->setEnabled(false);
	buttonRemove->setEnabled(false);
	buttonUpdate->setEnabled(false);
	buttonFilter->setEnabled(true);
	buttonSave->setEnabled(true);
	buttonNext->setEnabled(true);
	myList->setEnabled(true);
}

void GUI1::add()
{
	vector<string> validateVector;
	validateVector.push_back(lineEditId->text().toStdString());
	validateVector.push_back(lineEditMeasurement->text().toStdString());
	validateVector.push_back(lineEditImageLevel->text().toStdString());
	validateVector.push_back(lineEditQuantity->text().toStdString());
	validateVector.push_back(lineEditPhotograph->text().toStdString());

	try {
		validateData(validateVector);
	}
	catch (exception& ex) {
		QMessageBox m;
		m.setText(ex.what());
		m.exec();
		return;
	}

	string id = lineEditId->text().toStdString();
	string measurement = lineEditMeasurement->text().toStdString();
	double imageLevel = lineEditImageLevel->text().toDouble();
	string photograph = lineEditPhotograph->text().toStdString();
	double quantity = lineEditQuantity->text().toDouble();
	
	
	

	try {
		this->service->addDataToRepository(id, measurement, imageLevel, quantity, photograph);
		this->listPopulate();
	}
	catch (exception& exception)
	{
		QMessageBox message;
		message.critical(0,"ERROR",exception.what());
		//message.exec();
		//cout << "Error: " << exception.what() << "\n";
		return;
	}
}

void GUI1::remove()
{
	string id = lineEditId->text().toStdString();
	try {
		this->service->deleteDatatoRepository(id);
		this->listPopulate();
	}
	catch (exception &ex) {
		QMessageBox message;
		message.setText(ex.what());
		message.exec();
		return;
	}
}

void GUI1::update()
{
	vector<string> validateVector;
	validateVector.push_back(lineEditId->text().toStdString());
	validateVector.push_back(lineEditMeasurement->text().toStdString());
	validateVector.push_back(lineEditImageLevel->text().toStdString());
	validateVector.push_back(lineEditQuantity->text().toStdString());
	validateVector.push_back(lineEditPhotograph->text().toStdString());

	try {
		validateData(validateVector);
	}
	catch (exception& ex) {
		QMessageBox m;
		m.setText(ex.what());
		m.exec();
		return;
	}

	string id = lineEditId->text().toStdString();
	string measurement = lineEditMeasurement->text().toStdString();
	double imageLevel = lineEditImageLevel->text().toDouble();
	string photograph = lineEditPhotograph->text().toStdString();
	double quantity = lineEditQuantity->text().toDouble();

	try {
		this->service->updateDataToRepository(id, measurement, imageLevel, quantity, photograph);
		this->listPopulate();
	}
	catch (exception& exception)
	{
		QMessageBox message;
		message.setText(exception.what());
		message.exec();
		//cout << "Error: " << exception.what() << "\n";
		return;
	}
}

void GUI1::listPopulate()
{
	
	listArchives->clear();
	vector<Data> niggaArray = this->service->getALL();
	for (auto i : niggaArray)
		listArchives->addItem(QString::fromStdString(i.toString()));
	
}

void GUI1::myFilePopulate()
{
	listMyFile->clear();
	vector<Data> niggaArray = this->service->getALLmyList();
	for (auto i : niggaArray)
		listMyFile->addItem(QString::fromStdString(i.toString()));
}

void GUI1::next()
{
 	if(index == this->service->getthis())
		index = 0;
	vector<Data> vector = this->service->getALL();
	Data data = vector[index];
	
	QMessageBox message;
	message.setText(QString::fromStdString(data.toString()));
	message.exec();
	index++;

}

void GUI1::save()
{
	string id = lineEditId->text().toStdString();
	try {
		Data x = this->service->getData(id);
		this->service->saveService(id);
		this->myFilePopulate();
		myLittleModel->emitAllDataChanged();
	}
	catch (exception &ex) {
		QMessageBox message;
		message.setText(ex.what());
		message.exec();
		return;
	}
}

void GUI1::filter()
{
	vector<Data> vector = this->service->getALL();
	std::vector<Data> blabla(vector.size());
	QMessageBox message;
	QString dataString;
 
	string measurement = lineEditMeasurement->text().toStdString();
	double quantity = lineEditQuantity->text().toDouble();

	auto it = copy_if(vector.begin(), vector.end(), blabla.begin(), [measurement, quantity](Data data) { return data.getMeasurement() == measurement && data.getQuantity() >= quantity; });
		blabla.resize(distance(blabla.begin(), it));
	for (auto blait : blabla)
	{
		dataString.append(QString::fromStdString(blait.toString()));
		dataString.append("\n");
	}
	message.setText(dataString);
	message.exec();
}

void GUI1::myNewTableFunction()
{
	//this->mylis.show();
	
	newTableWindow->show();
	newTableWindow2->show();
}

void GUI1::Undo()
{
	try {
		this->service->undoAction();
		this->listPopulate();
	}
	catch (exception& ex)
	{
		QMessageBox message;
		message.setText(ex.what());
		message.exec();
		return;
	}
}

void GUI1::Redo()
{
	try {
		this->service->RedoAction();
		this->listPopulate();
	}
	catch (exception& ex)
	{
		QMessageBox message;
		message.setText(ex.what());
		message.exec();
		return;
	}
}
