/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *saveButton;
    QPushButton *resetButton;
    QLabel *author_label;
    QLineEdit *author_text;
    QLineEdit *name_text;
    QLabel *name_label;
    QLabel *id_label;
    QLineEdit *id_text;
    QLineEdit *book_filling;
    QLabel *book_filling_label;
    QRadioButton *paper_button;
    QRadioButton *electronic_button;
    QLabel *type_label;
    QCheckBox *genre1_checkBox;
    QCheckBox *genre2_checkBox;
    QCheckBox *genre3_checkBox;
    QLabel *genre_label;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(613, 663);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(390, 470, 90, 29));
        saveButton->setAutoFillBackground(false);
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(160, 470, 90, 29));
        author_label = new QLabel(centralwidget);
        author_label->setObjectName("author_label");
        author_label->setGeometry(QRect(170, 40, 71, 20));
        author_text = new QLineEdit(centralwidget);
        author_text->setObjectName("author_text");
        author_text->setGeometry(QRect(280, 40, 91, 20));
        name_text = new QLineEdit(centralwidget);
        name_text->setObjectName("name_text");
        name_text->setGeometry(QRect(260, 74, 211, 16));
        name_label = new QLabel(centralwidget);
        name_label->setObjectName("name_label");
        name_label->setGeometry(QRect(170, 70, 71, 21));
        id_label = new QLabel(centralwidget);
        id_label->setObjectName("id_label");
        id_label->setGeometry(QRect(170, 100, 31, 20));
        id_text = new QLineEdit(centralwidget);
        id_text->setObjectName("id_text");
        id_text->setGeometry(QRect(290, 104, 113, 16));
        book_filling = new QLineEdit(centralwidget);
        book_filling->setObjectName("book_filling");
        book_filling->setGeometry(QRect(260, 134, 113, 16));
        book_filling_label = new QLabel(centralwidget);
        book_filling_label->setObjectName("book_filling_label");
        book_filling_label->setGeometry(QRect(142, 130, 91, 20));
        paper_button = new QRadioButton(centralwidget);
        paper_button->setObjectName("paper_button");
        paper_button->setGeometry(QRect(250, 180, 141, 25));
        electronic_button = new QRadioButton(centralwidget);
        electronic_button->setObjectName("electronic_button");
        electronic_button->setGeometry(QRect(330, 181, 111, 25));
        type_label = new QLabel(centralwidget);
        type_label->setObjectName("type_label");
        type_label->setGeometry(QRect(140, 180, 101, 20));
        genre1_checkBox = new QCheckBox(centralwidget);
        genre1_checkBox->setObjectName("genre1_checkBox");
        genre1_checkBox->setGeometry(QRect(240, 210, 92, 25));
        genre2_checkBox = new QCheckBox(centralwidget);
        genre2_checkBox->setObjectName("genre2_checkBox");
        genre2_checkBox->setGeometry(QRect(240, 240, 92, 25));
        genre3_checkBox = new QCheckBox(centralwidget);
        genre3_checkBox->setObjectName("genre3_checkBox");
        genre3_checkBox->setGeometry(QRect(240, 270, 92, 25));
        genre_label = new QLabel(centralwidget);
        genre_label->setObjectName("genre_label");
        genre_label->setGeometry(QRect(146, 210, 63, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 613, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        author_label->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        name_label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        id_label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264", nullptr));
        book_filling_label->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        paper_button->setText(QCoreApplication::translate("MainWindow", "Paper", nullptr));
        electronic_button->setText(QCoreApplication::translate("MainWindow", "Electronic", nullptr));
        type_label->setText(QCoreApplication::translate("MainWindow", " \320\242\320\270\320\277 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));
        genre1_checkBox->setText(QCoreApplication::translate("MainWindow", "Detective", nullptr));
        genre2_checkBox->setText(QCoreApplication::translate("MainWindow", "Fantasy", nullptr));
        genre3_checkBox->setText(QCoreApplication::translate("MainWindow", "Novel", nullptr));
        genre_label->setText(QCoreApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200\321\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\270\320\263\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
