#include "cameraget.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    cameraGet w;
    w.show();
    return a.exec();
}
