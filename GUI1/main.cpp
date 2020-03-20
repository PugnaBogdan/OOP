#pragma once

#include "GUI1.h"
#include <QtWidgets/QApplication>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


int main(int argc, char *argv[])
{
	Repository repository{};
	RepositoryMyFile* myList{};
	Service services{ repository, myList };
	QApplication a(argc, argv);
	GUI1 w{&services};
	//MyModel model{}
	w.show();
	return a.exec();
}
