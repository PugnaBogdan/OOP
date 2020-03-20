#include "MyList.h"
#include <qcolor.h>
#include <string>

MyModel::MyModel(Service* r) : service{ r }
{
	this->service = r;
}

MyModel::~MyModel()
{

}



int MyModel::rowCount(const QModelIndex & parent) const
{
	return this->service->getthisMyList();
}

int MyModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant MyModel::data(const QModelIndex & index, int role) const
{

	int row = index.row();
	int col = index.column();



	Data currentStudent = this->service->getALLmyList()[row];

	if (role == Qt::DisplayRole)
	{
		switch (col)
		{
		case 0:
			return QString::fromStdString(currentStudent.getId());
		case 1:
			return QString::fromStdString(currentStudent.getMeasurement());
		case 2:
			return QString::number(currentStudent.getImageClarityLevel());
		case 3:
			return QString::number(currentStudent.getQuantity());
		case 4:
			return QString::fromStdString(currentStudent.getPhotograph());
		default:
			break;
		}
	}
	return QVariant();
}
QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section) {
		case 0:
			return "Id";
		case 1:
			return "Measurement";
		case 2:
			return "ImageClarityLevel";
		case 3:
			return "Quantity";
		case 4:
			return "Photography";
		}
	}
	return QVariant();
}


Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

void MyModel::emitAllDataChanged()
{
	//index(repo.getsize() - 1, 4);
	emit layoutChanged();
}
