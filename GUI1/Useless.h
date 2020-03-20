#pragma once
#include "Repository.h"
#include <QWidget>
#include "ui_Useless.h"
#include "MyList.h"

class newTableClass : public QWidget
{
	Q_OBJECT

private:
	MyModel * model;
public:
	newTableClass(MyModel* m,QWidget *parent = Q_NULLPTR);
	~newTableClass();
	void uppdate();
private:
	Ui::Useless ui;
};
