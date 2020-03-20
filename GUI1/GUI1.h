#pragma once
#include "Service.h"
#include "Validator.h"
#include <QtWidgets/QMainWindow>
#include "ui_GUI1.h"
#include "MyFileModel.h"
#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMainWindow>
#include <QShortcut>

#include "Useless.h"
#include "MyList.h"

class GUI1 : public QWidget
{
	Q_OBJECT

public:
	GUI1(Service * service,QWidget *parent = Q_NULLPTR);
	void run();
	void initialize();
	void initialize2();
	void administratorMode();
	void userMode();
	void add();
	void remove();
	void update();
	void listPopulate();
	void myFilePopulate();
	void next();
	void save();
	void filter();

	void myNewTableFunction();

public slots:

	void Undo();
	void Redo();

private:
	Ui::GUI1Class ui;
	Service* service;
	RepositoryMyFile* repository;
	string mode;
	int index = 0;
	MyModel* myLittleModel;
	newTableClass* newTableWindow;
	newTableClass* newTableWindow2;


	QListWidget* listArchives;
	QListWidget* listMyFile;

	QHBoxLayout* layoutHorizontalGeneral;
	QVBoxLayout *firstVerticalLayout;
	QVBoxLayout *secondVerticalLayout;
	QVBoxLayout *thirdVerticalLayout;
	QHBoxLayout* ArchivesButtonsHorizontalLayout;
	QHBoxLayout* MyFileButtonsHorizontalLayout;

	QLabel* labelHeaderArchives;
	QLabel* labelId;
	QLabel* labelQuantity;
	QLabel* labelMeasurement;
	QLabel* labelImageLevel;
	QLabel* labelPhotograph;
	QLabel* labelHeaderShoppingBasket;

	QLineEdit *lineEditId;
	QLineEdit *lineEditQuantity;
	QLineEdit *lineEditMeasurement;
	QLineEdit *lineEditImageLevel;
	QLineEdit *lineEditPhotograph;

	QFormLayout *formLayoutData;

	QPushButton *myList;
	QPushButton *buttonAdd;
	QPushButton *buttonRemove;
	QPushButton *buttonUpdate;
	QPushButton *buttonFilter;
	QPushButton *buttonAuxiliar;
	QPushButton *buttonSave;
	QPushButton *buttonNext;
	QPushButton *buttonChart;
	QPushButton *buttonUser;
	QPushButton *buttonAdministrator;
	QHBoxLayout *startLayout;
	QFormLayout *startForm;
	QPushButton *buttonStart;
	QLineEdit *lineEditFile;
	QLineEdit *lineEditMyFile;
	QLineEdit *lineEditStartingMode;
	QLabel* labelFile;
	QLabel* labelMyFile;
	QLabel* labelStartingMode;

	QPushButton * undo;
	QPushButton * redo;

	QMainWindow *mainWindow;
};
