/********************************************************************************
** Form generated from reading UI file 'camaraget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMARAGET_H
#define UI_CAMARAGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camaraGet
{
public:
    QWidget *centralWidget;
    QPushButton *open;
    QPushButton *pic;
    QLabel *label;
    QLabel *label_2;
    QPushButton *closeCam;
    QPushButton *savepic;
    QPushButton *openpic;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *camaraGet)
    {
        if (camaraGet->objectName().isEmpty())
            camaraGet->setObjectName(QStringLiteral("camaraGet"));
        camaraGet->resize(856, 607);
        centralWidget = new QWidget(camaraGet);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        open = new QPushButton(centralWidget);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(30, 500, 91, 29));
        pic = new QPushButton(centralWidget);
        pic->setObjectName(QStringLiteral("pic"));
        pic->setGeometry(QRect(150, 500, 91, 29));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 421, 391));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(480, 30, 381, 371));
        closeCam = new QPushButton(centralWidget);
        closeCam->setObjectName(QStringLiteral("closeCam"));
        closeCam->setGeometry(QRect(440, 500, 91, 29));
        savepic = new QPushButton(centralWidget);
        savepic->setObjectName(QStringLiteral("savepic"));
        savepic->setGeometry(QRect(290, 500, 91, 29));
        openpic = new QPushButton(centralWidget);
        openpic->setObjectName(QStringLiteral("openpic"));
        openpic->setGeometry(QRect(570, 500, 91, 29));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 450, 91, 29));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 450, 91, 29));
        camaraGet->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(camaraGet);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 856, 26));
        camaraGet->setMenuBar(menuBar);
        mainToolBar = new QToolBar(camaraGet);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        camaraGet->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(camaraGet);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        camaraGet->setStatusBar(statusBar);

        retranslateUi(camaraGet);

        QMetaObject::connectSlotsByName(camaraGet);
    } // setupUi

    void retranslateUi(QMainWindow *camaraGet)
    {
        camaraGet->setWindowTitle(QApplication::translate("camaraGet", "camaraGet", Q_NULLPTR));
        open->setText(QApplication::translate("camaraGet", "openCam", Q_NULLPTR));
        pic->setText(QApplication::translate("camaraGet", "picture", Q_NULLPTR));
        label->setText(QApplication::translate("camaraGet", "Label 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("camaraGet", "Label 2", Q_NULLPTR));
        closeCam->setText(QApplication::translate("camaraGet", "closeCam", Q_NULLPTR));
        savepic->setText(QApplication::translate("camaraGet", "savepic", Q_NULLPTR));
        openpic->setText(QApplication::translate("camaraGet", "openpic", Q_NULLPTR));
        pushButton->setText(QApplication::translate("camaraGet", "Left", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("camaraGet", "Right", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class camaraGet: public Ui_camaraGet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMARAGET_H
