#-------------------------------------------------
#
# Project created by QtCreator 2018-03-15T11:14:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ablum
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    switchcontrol.cpp \
    hled.cpp \
    camera.cpp \
    servo.cpp \
    infrared.cpp \
    controller.cpp

HEADERS += \
        mainwindow.h \
    switchcontrol.h \
    hled.h \
    camera.h \
    servo.h \
    infrared.h \
    controller.h

FORMS += \
        mainwindow.ui

#opencv路径
linux*{
OPENCV_ROOT = /usr/local
INCLUDEPATH += $(OPENCV_ROOT)/include
DEPENDPATH += $(OPENCV_ROOT)/include
LIBS +=  -L$(OPENCV_ROOT)/lib/ -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d \
                                -lopencv_flann -lopencv_gpu -lopencv_highgui -lopencv_imgproc -lopencv_legacy \
                                -lopencv_ml -lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo \
                                -lopencv_stitching -lopencv_superres -lopencv_video -lopencv_videostab
}

DISTFILES +=

RESOURCES += \
    resource.qrc

LIBS += -lwiringPi
