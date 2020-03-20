#pragma once
#include <QWidget>
#include "MyList.h"

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
#include <QtWidgets/QMainWindow>
#include <QTableView>

class newTableView : public QWidget
{
	Q_OBJECT

private:
	MyModel* model;
	QTableView * table;

public:
	newTableView(MyModel* m, QWidget *parent = Q_NULLPTR);
	~newTableView();

private:


};