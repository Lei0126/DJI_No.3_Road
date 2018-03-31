#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTimer>
#include <QThread>
#include <QHash>
#include "camera.h"
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void modeChange(const char mode);
    void angleChange(const int degree);
    void routeTimeChange(const int value);

public slots:
    void onBtnLeftPressed();
    void onBtnRightPressed();
    void onBtnCapturePressed();
    void onSwAutoToggled(const bool status);
    void onSwScanToggled(const bool status);
    void onSwRouteToggled(const bool status);
    void onSliderChanged(const int value);
    void onSliderRouteTimeChanged(const int value);
    void onPainted();
    void onCameraOpened(const bool isOpened);
    void onItemChanged(QListWidgetItem* item);
    void onCaptured(const QString name);

private:
    void initForm();
    void initConn();
    void setAutoly(bool isauto);
    Ui::MainWindow  *ui;
    Camera          *m_cam;
    Controller      *m_controller;
    QThread         m_threadCam;
    QThread         m_threadControl;
};

#endif // MAINWINDOW_H
