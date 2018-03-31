#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <unistd.h>
#include <fcntl.h>
#include <QDateTime>

#define Print()     qDebug() << " file:" << __FILE__ << " line:" <<__LINE__ <<" "
#define W_ICONSIZE  100
#define H_ICONSIZE  75

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_cam = new Camera();
    m_controller = new Controller(m_cam);

    initForm();
    initConn();

    m_cam->moveToThread(&m_threadCam);
    m_threadCam.start();

    m_controller->moveToThread(&m_threadControl);
    m_threadControl.start();
}

MainWindow::~MainWindow()
{
    m_threadCam.quit();
    m_threadControl.quit();
    m_threadCam.wait();
    m_threadControl.wait();

    delete m_controller;
    delete m_cam;
    delete ui;
}

void MainWindow::onBtnLeftPressed()
{
    ui->slider_servo->setValue(m_controller->nowAngle()-10);
}

void MainWindow::onBtnRightPressed()
{
    ui->slider_servo->setValue(m_controller->nowAngle()+10);
}

void MainWindow::onBtnCapturePressed()
{
    Print() << QDateTime::currentDateTime().toString("mm.ss.zzz");
    ui->btn_capture->setDisabled(true);
    m_cam->capture();
}

void MainWindow::onSwRouteToggled(const bool status)
{
    emit modeChange(status ? Controller::ROUTING : Controller::AUTO);
}

void MainWindow::onSliderRouteTimeChanged(const int value)
{
    emit routeTimeChange(value);
}

void MainWindow::onSliderChanged(int value)
{
    if(value != m_controller->nowAngle())
        emit angleChange(value);
}

void MainWindow::onPainted()
{
    QPixmap pix = QPixmap::fromImage(m_cam->m_image);
    pix = pix.scaled(ui->lb_video->size(),Qt::KeepAspectRatio);
    ui->lb_video->setPixmap(pix);
}

void MainWindow::onCameraOpened(bool isOpened)
{
    if(isOpened) {
        ui->led_Camera->turnOn();
    } else {
        ui->led_Camera->turnOff();
    }
}

void MainWindow::onItemChanged(QListWidgetItem *item)
{
    if(!ui->sw_scan->isToggled())
        return;
    QString name = m_cam->m_fullPath + "/" + item->text();
    QPixmap pix = QPixmap(name);
    pix = pix.scaled(ui->lb_video->size(),Qt::KeepAspectRatio);
    ui->lb_video->setPixmap(pix);
}

void MainWindow::onCaptured(const QString name)
{
    ui->btn_capture->setEnabled(true);
    if(access(name.toLatin1().data(),0) == -1) return;
    QPixmap objPixmap(name);
    QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(W_ICONSIZE,H_ICONSIZE))),\
                                                 name.split('/').last());
    //设置单元项的宽度和高度
    pItem->setSizeHint(QSize(W_ICONSIZE,W_ICONSIZE));
    ui->listWidget->insertItem(0, pItem);
    //Print() << QDateTime::currentDateTime().toString("mm.ss.zzz");
}

void MainWindow::onSwAutoToggled(bool status)
{
    setAutoly(status);
    emit modeChange(status ? Controller::AUTO : Controller::MANUAL);
}

void MainWindow::onSwScanToggled(bool status)
{
    //setScan(status);
    if( m_threadCam.isRunning() ) {
        if(status) {
            disconnect(m_cam, SIGNAL(ready()), this, SLOT(onPainted()));
            connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(onItemChanged(QListWidgetItem*)));
        } else {
            connect(m_cam, SIGNAL(ready()), SLOT(onPainted()));
            disconnect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemChanged(QListWidgetItem*)));
        }
    }
}

void MainWindow::initForm()
{
    ui->led_Auto->turnOff();
    ui->led_Camera->turnOff();
    ui->led_Auto->setColor(Qt::green);
    ui->led_Camera->setColor(Qt::red);
    ui->sw_autoOrMan->setToggle(true);
    ui->sw_scan->setToggle(false);
    ui->listWidget->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
    ui->listWidget->setResizeMode(QListView::Adjust);
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setMovement(QListView::Static);
    ui->listWidget->setSpacing(10);

    setAutoly(true);
    onPainted();
}

void MainWindow::initConn()
{
    connect(ui->btn_turnLeft, SIGNAL(clicked(bool)), SLOT(onBtnLeftPressed()));
    connect(ui->btn_turnRight, SIGNAL(clicked(bool)), SLOT(onBtnRightPressed()));
    connect(ui->btn_capture, SIGNAL(clicked(bool)), SLOT(onBtnCapturePressed()));
    connect(ui->sw_autoOrMan, SIGNAL(toggled(bool)), SLOT(onSwAutoToggled(bool)));
    connect(ui->sw_scan, SIGNAL(toggled(bool)), SLOT(onSwScanToggled(bool)));
    connect(ui->sw_RouteOrAuto, SIGNAL(toggled(bool)), SLOT(onSwRouteToggled(bool)));
    connect(ui->slider_servo, SIGNAL(valueChanged(int)), SLOT(onSliderChanged(int)));
    connect(ui->slider_routeTime, SIGNAL(valueChanged(int)), SLOT(onSliderRouteTimeChanged(int)));

    connect(m_cam, SIGNAL(ready()), SLOT(onPainted()));
    connect(m_cam, SIGNAL(opened(bool)), SLOT(onCameraOpened(bool)));
    connect(m_cam, SIGNAL(captured(QString)), SLOT(onCaptured(QString)));

    connect(&m_threadCam, SIGNAL(started()), m_cam, SLOT(open()));
    connect(&m_threadControl, SIGNAL(started()), m_controller, SLOT(init()));

    connect(m_controller, SIGNAL(angleChanged(int)), ui->slider_servo, SLOT(setValue(int)));

    connect(this, SIGNAL(modeChange(char)), m_controller, SLOT(setMode(char)));
    connect(this, SIGNAL(angleChange(int)), m_controller, SLOT(setAngle(int)));
    connect(this, SIGNAL(routeTimeChange(int)), m_controller, SLOT(changeRouteTime(int)));
}

void MainWindow::setAutoly(bool isauto)
{
    if(isauto) {
        ui->stackedWidget->setCurrentWidget(ui->page_auto);
        ui->slider_servo->setDisabled(true);
        ui->led_Auto->turnOn(true);
    } else {
        ui->stackedWidget->setCurrentWidget(ui->page_man);
        ui->slider_servo->setEnabled(true);
        ui->led_Auto->turnOff(true);
    }
}
