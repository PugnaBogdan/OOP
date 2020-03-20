#include "MyFileModel.h"
#include <qmessagebox.h>

newTableView::newTableView(MyModel * m, QWidget *parent)
	: QWidget(parent), model{ m }
{
	table = new QTableView;
	table->setModel(this->model);
}

newTableView::~newTableView()
{
}
