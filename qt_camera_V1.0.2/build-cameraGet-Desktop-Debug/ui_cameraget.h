/********************************************************************************
** Form generated from reading UI file 'cameraget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAGET_H
#define UI_CAMERAGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cameraGet
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
    QPushButton *pushButton_3;
    QSlider *degreeSlider;
    QSlider *verticalSlider;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cameraGet)
    {
        if (cameraGet->objectName().isEmpty())
            cameraGet->setObjectName(QStringLiteral("cameraGet"));
        cameraGet->setEnabled(true);
        cameraGet->resize(1008, 690);
        cameraGet->setAnimated(true);
        centralWidget = new QWidget(cameraGet);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        open = new QPushButton(centralWidget);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(90, 530, 91, 29));
        pic = new QPushButton(centralWidget);
        pic->setObjectName(QStringLiteral("pic"));
        pic->setGeometry(QRect(220, 530, 91, 29));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 50, 511, 391));
        label->setFrameShape(QFrame::Box);
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/\344\272\214\346\234\210\345\205\260.jpg")));
        label->setScaledContents(true);
        label->setMargin(0);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(530, 50, 461, 351));
        label_2->setCursor(QCursor(Qt::ArrowCursor));
        label_2->setFrameShape(QFrame::Box);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/\345\244\247\347\226\206\346\227\240\344\272\272\346\234\272.jpg")));
        label_2->setScaledContents(true);
        closeCam = new QPushButton(centralWidget);
        closeCam->setObjectName(QStringLiteral("closeCam"));
        closeCam->setGeometry(QRect(510, 530, 91, 29));
        savepic = new QPushButton(centralWidget);
        savepic->setObjectName(QStringLiteral("savepic"));
        savepic->setGeometry(QRect(360, 530, 91, 29));
        openpic = new QPushButton(centralWidget);
        openpic->setObjectName(QStringLiteral("openpic"));
        openpic->setGeometry(QRect(640, 530, 91, 29));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 470, 121, 29));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 470, 111, 29));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(530, 470, 111, 29));
        degreeSlider = new QSlider(centralWidget);
        degreeSlider->setObjectName(QStringLiteral("degreeSlider"));
        degreeSlider->setGeometry(QRect(820, 430, 20, 141));
        degreeSlider->setMaximum(180);
        degreeSlider->setValue(90);
        degreeSlider->setOrientation(Qt::Vertical);
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(870, 430, 20, 141));
        verticalSlider->setMinimum(5);
        verticalSlider->setMaximum(100);
        verticalSlider->setValue(50);
        verticalSlider->setOrientation(Qt::Vertical);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(890, 510, 51, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(770, 510, 51, 21));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(770, 460, 50, 41));
        spinBox->setMinimum(0);
        spinBox->setMaximum(180);
        spinBox->setValue(0);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(410, 10, 261, 31));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setScaledContents(false);
        cameraGet->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cameraGet);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1008, 26));
        cameraGet->setMenuBar(menuBar);
        mainToolBar = new QToolBar(cameraGet);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        cameraGet->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(cameraGet);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        cameraGet->setStatusBar(statusBar);

        retranslateUi(cameraGet);
        QObject::connect(degreeSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(cameraGet);
    } // setupUi

    void retranslateUi(QMainWindow *cameraGet)
    {
        cameraGet->setWindowTitle(QApplication::translate("cameraGet", "cameraGet", Q_NULLPTR));
        open->setText(QApplication::translate("cameraGet", "OpenCam", Q_NULLPTR));
        pic->setText(QApplication::translate("cameraGet", "Takepic", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        closeCam->setText(QApplication::translate("cameraGet", "CloseCam", Q_NULLPTR));
        savepic->setText(QApplication::translate("cameraGet", "Savepic", Q_NULLPTR));
        openpic->setText(QApplication::translate("cameraGet", "Openpic", Q_NULLPTR));
        pushButton->setText(QApplication::translate("cameraGet", "Infrared_mode", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("cameraGet", "Period_mode", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("cameraGet", "Auto/Manual", Q_NULLPTR));
        label_3->setText(QApplication::translate("cameraGet", "Speed", Q_NULLPTR));
        label_4->setText(QApplication::translate("cameraGet", "Degree", Q_NULLPTR));
        label_5->setText(QApplication::translate("cameraGet", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600; color:#729fcf;\">DJI_No.3_Road</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cameraGet: public Ui_cameraGet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAGET_H
