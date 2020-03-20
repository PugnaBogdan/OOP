#include "Useless.h"

newTableClass::newTableClass(MyModel* m, QWidget *parent)
	: QWidget(parent), model{ m }
{
	ui.setupUi(this);
	this->ui.tableView->setModel(this->model);
	


}

newTableClass::~newTableClass()
{

}

void newTableClass::uppdate()
{
	this->ui.tableView->setModel(this->model);
	ui.setupUi(this);
}
