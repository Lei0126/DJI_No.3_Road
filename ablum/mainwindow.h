#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTimer>
#include <QThread>
#include <QHash>
#include "camera.h"
#include "servo.h"

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
    void capture();

public slots:
    void onBtnLeftPressed();
    void onBtnRightPressed();
    void onBtnCapturePressed();
    void onSwAutoToggled(bool status);
    void onSwScanToggled(bool status);
    void onSliderChanged(int value);
    void onPainted();
    void onCameraOpened(bool isOpened);
    void onItemChanged(QListWidgetItem* item);
    void onTimeout();

private:
    void initForm();
    void initConn();
    void setAutoly(bool isauto);
    void setScan(bool isscan);
    void addList();
    Ui::MainWindow  *ui;
    Camera          m_cam;
    Servo           m_servo;
    QThread         m_camThread;
    QTimer          m_camTimer;
    QTimer          m_listTimer;
    QHash<QString, QListWidgetItem*> m_hash;
};

#endif // MAINWINDOW_H
