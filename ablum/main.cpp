#include "mainwindow.h"
#include <QApplication>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
    wiringPiSetup();
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    return a.exec();
}
