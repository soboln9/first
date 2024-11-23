/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *sum_button;
    QTextEdit *source_edit;
    QLineEdit *sum_edit;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1210, 736);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sum_button = new QPushButton(centralwidget);
        sum_button->setObjectName("sum_button");
        sum_button->setGeometry(QRect(780, 520, 301, 141));
        QFont font;
        font.setPointSize(20);
        sum_button->setFont(font);
        source_edit = new QTextEdit(centralwidget);
        source_edit->setObjectName("source_edit");
        source_edit->setGeometry(QRect(10, 130, 651, 541));
        sum_edit = new QLineEdit(centralwidget);
        sum_edit->setObjectName("sum_edit");
        sum_edit->setGeometry(QRect(840, 350, 161, 61));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 60, 251, 61));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(870, 280, 101, 51));
        QFont font1;
        font1.setPointSize(16);
        label_2->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1210, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        sum_button->setText(QCoreApplication::translate("MainWindow", "Calculate checksum", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Source text", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CheckSum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
