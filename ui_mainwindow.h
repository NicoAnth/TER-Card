/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *v1;
    QHBoxLayout *h1;
    QWidget *blockW;
    QHBoxLayout *h2;
    QHBoxLayout *h3;
    QPushButton *create_userPB;
    QMenuBar *menubar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1076, 665);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        v1 = new QVBoxLayout();
        v1->setObjectName(QString::fromUtf8("v1"));
        h1 = new QHBoxLayout();
        h1->setObjectName(QString::fromUtf8("h1"));
        blockW = new QWidget(widget);
        blockW->setObjectName(QString::fromUtf8("blockW"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(blockW->sizePolicy().hasHeightForWidth());
        blockW->setSizePolicy(sizePolicy);
        blockW->setMinimumSize(QSize(0, 0));
        blockW->setSizeIncrement(QSize(0, 0));
        blockW->setBaseSize(QSize(2500, 0));
        blockW->setMouseTracking(false);

        h1->addWidget(blockW);


        v1->addLayout(h1);

        h2 = new QHBoxLayout();
        h2->setObjectName(QString::fromUtf8("h2"));

        v1->addLayout(h2);

        h3 = new QHBoxLayout();
        h3->setObjectName(QString::fromUtf8("h3"));
        create_userPB = new QPushButton(widget);
        create_userPB->setObjectName(QString::fromUtf8("create_userPB"));
        create_userPB->setMaximumSize(QSize(200, 25));

        h3->addWidget(create_userPB);


        v1->addLayout(h3);


        gridLayout_2->addLayout(v1, 0, 1, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1076, 23));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        create_userPB->setText(QApplication::translate("MainWindow", "Cr\303\251er utilisateur", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
