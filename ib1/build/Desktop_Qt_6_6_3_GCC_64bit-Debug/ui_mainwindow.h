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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *key;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_5;
    QLabel *closetexthex;
    QLabel *closetext2;
    QTextEdit *opentext;
    QTextEdit *closetext;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1197, 726);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        key = new QLineEdit(centralwidget);
        key->setObjectName("key");
        key->setGeometry(QRect(30, 120, 231, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 70, 141, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(700, 10, 111, 17));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(310, 70, 121, 71));
        closetexthex = new QLabel(centralwidget);
        closetexthex->setObjectName("closetexthex");
        closetexthex->setGeometry(QRect(310, 40, 101, 20));
        closetext2 = new QLabel(centralwidget);
        closetext2->setObjectName("closetext2");
        closetext2->setGeometry(QRect(710, 290, 91, 20));
        opentext = new QTextEdit(centralwidget);
        opentext->setObjectName("opentext");
        opentext->setGeometry(QRect(590, 40, 321, 241));
        closetext = new QTextEdit(centralwidget);
        closetext->setObjectName("closetext");
        closetext->setGeometry(QRect(590, 330, 321, 281));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1197, 22));
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
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207 \321\210\320\270\321\204\321\200\320\276\320\262\320\260\320\275\320\270\321\217 hex", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Open text", nullptr));
        closetexthex->setText(QCoreApplication::translate("MainWindow", "Close text hex", nullptr));
        closetext2->setText(QCoreApplication::translate("MainWindow", "Close text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
