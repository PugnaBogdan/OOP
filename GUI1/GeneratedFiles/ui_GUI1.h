/********************************************************************************
** Form generated from reading UI file 'GUI1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI1_H
#define UI_GUI1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUI1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUI1Class)
    {
        if (GUI1Class->objectName().isEmpty())
            GUI1Class->setObjectName(QString::fromUtf8("GUI1Class"));
        GUI1Class->resize(600, 400);
        menuBar = new QMenuBar(GUI1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GUI1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUI1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GUI1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(GUI1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GUI1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GUI1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUI1Class->setStatusBar(statusBar);

        retranslateUi(GUI1Class);

        QMetaObject::connectSlotsByName(GUI1Class);
    } // setupUi

    void retranslateUi(QMainWindow *GUI1Class)
    {
        GUI1Class->setWindowTitle(QApplication::translate("GUI1Class", "GUI1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI1Class: public Ui_GUI1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI1_H
