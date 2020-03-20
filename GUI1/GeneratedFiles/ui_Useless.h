/********************************************************************************
** Form generated from reading UI file 'Useless.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USELESS_H
#define UI_USELESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Useless
{
public:
    QTableView *tableView;

    void setupUi(QWidget *Useless)
    {
        if (Useless->objectName().isEmpty())
            Useless->setObjectName(QString::fromUtf8("Useless"));
        Useless->resize(400, 300);
        tableView = new QTableView(Useless);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(Useless);

        QMetaObject::connectSlotsByName(Useless);
    } // setupUi

    void retranslateUi(QWidget *Useless)
    {
        Useless->setWindowTitle(QApplication::translate("Useless", "Useless", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Useless: public Ui_Useless {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USELESS_H
