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
#include <QtWidgets/QCheckBox>
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
    QLineEdit *key;
    QLabel *label;
    QLabel *label_2;
    QLabel *closetexthex;
    QLabel *closetext2;
    QTextEdit *opentext;
    QTextEdit *closetext;
    QTextEdit *hextext;
    QCheckBox *des_box;
    QCheckBox *rsa_box;
    QLineEdit *n;
    QLineEdit *e;
    QLineEdit *d;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *encrsa;
    QPushButton *decrsa;
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
        label_2->setGeometry(QRect(390, 30, 111, 17));
        closetexthex = new QLabel(centralwidget);
        closetexthex->setObjectName("closetexthex");
        closetexthex->setGeometry(QRect(710, 30, 101, 20));
        closetext2 = new QLabel(centralwidget);
        closetext2->setObjectName("closetext2");
        closetext2->setGeometry(QRect(730, 340, 91, 20));
        opentext = new QTextEdit(centralwidget);
        opentext->setObjectName("opentext");
        opentext->setGeometry(QRect(280, 70, 321, 241));
        closetext = new QTextEdit(centralwidget);
        closetext->setObjectName("closetext");
        closetext->setGeometry(QRect(610, 370, 321, 281));
        hextext = new QTextEdit(centralwidget);
        hextext->setObjectName("hextext");
        hextext->setGeometry(QRect(610, 70, 321, 241));
        des_box = new QCheckBox(centralwidget);
        des_box->setObjectName("des_box");
        des_box->setGeometry(QRect(990, 120, 92, 23));
        rsa_box = new QCheckBox(centralwidget);
        rsa_box->setObjectName("rsa_box");
        rsa_box->setGeometry(QRect(990, 160, 92, 23));
        n = new QLineEdit(centralwidget);
        n->setObjectName("n");
        n->setGeometry(QRect(960, 270, 113, 25));
        e = new QLineEdit(centralwidget);
        e->setObjectName("e");
        e->setGeometry(QRect(960, 320, 113, 25));
        d = new QLineEdit(centralwidget);
        d->setObjectName("d");
        d->setGeometry(QRect(960, 370, 113, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1010, 250, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1010, 300, 67, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1010, 350, 67, 17));
        encrsa = new QPushButton(centralwidget);
        encrsa->setObjectName("encrsa");
        encrsa->setGeometry(QRect(970, 460, 91, 81));
        decrsa = new QPushButton(centralwidget);
        decrsa->setObjectName("decrsa");
        decrsa->setGeometry(QRect(1070, 460, 91, 81));
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
        des_box->setText(QCoreApplication::translate("MainWindow", "DES", nullptr));
        rsa_box->setText(QCoreApplication::translate("MainWindow", "RSA", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "n", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
        encrsa->setText(QCoreApplication::translate("MainWindow", "encrsa>>", nullptr));
        decrsa->setText(QCoreApplication::translate("MainWindow", "decrsa<<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
