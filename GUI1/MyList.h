#pragma once
#include <QAbstractTableModel>
#include "Service.h"

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


class MyModel :
	public QAbstractTableModel
{
private:
	Service* service;

public:
	MyModel(Service* servicee);
	~MyModel();
	
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	void emitAllDataChanged();
};


