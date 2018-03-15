#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <unistd.h>
#include <fcntl.h>

#define Print()     qDebug() << " file:" << __FILE__ << " line:" <<__LINE__ <<" "
#define W_ICONSIZE  100
#define H_ICONSIZE  75

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initForm();
    initConn();

    m_cam.moveToThread(&m_camThread);
    m_camThread.start();
    addList();
    m_camTimer.setInterval(30);
    m_listTimer.start(2000);
}

MainWindow::~MainWindow()
{
    m_camTimer.stop();
    m_camThread.quit();
    m_camThread.wait();
    delete ui;
}

void MainWindow::onBtnLeftPressed()
{
    ui->slider_servo->setValue(m_servo.nowAngle()-10);
}

void MainWindow::onBtnRightPressed()
{
    ui->slider_servo->setValue(m_servo.nowAngle()+10);
}

void MainWindow::onBtnCapturePressed()
{
    emit capture();
}

void MainWindow::onSliderChanged(int value)
{
    m_servo.setNowAngle(value);
}

void MainWindow::onPainted()
{
    QPixmap pix = QPixmap::fromImage(m_cam.m_image);
    pix.scaled(ui->lb_video->size(),Qt::KeepAspectRatio);
    ui->lb_video->setPixmap(pix);
}

void MainWindow::onCameraOpened(bool isOpened)
{
    if(isOpened) {
        ui->led_Camera->turnOn();
        m_camTimer.start();
    } else {
        ui->led_Camera->turnOff();
    }
}

void MainWindow::onItemChanged(QListWidgetItem *item)
{
    if(!ui->sw_scan->isToggled())
        return;
    QString name =  QCoreApplication::applicationDirPath() + item->text();
    ui->lb_video->setPixmap(QPixmap(name));
}

void MainWindow::onTimeout()
{
    addList();
}

void MainWindow::onSwAutoToggled(bool status)
{
    if(!ui->sw_scan->isToggled())
        setAutoly(status);
}

void MainWindow::onSwScanToggled(bool status)
{
    setScan(status);
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

    setScan(false);
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
    connect(ui->slider_servo, SIGNAL(valueChanged(int)), SLOT(onSliderChanged(int)));
    connect(&m_cam, SIGNAL(ready()), SLOT(onPainted()));
    connect(&m_cam, SIGNAL(opened(bool)), SLOT(onCameraOpened(bool)));
    connect(&m_listTimer, SIGNAL(timeout()), SLOT(onTimeout()));

    connect(&m_camThread, SIGNAL(started()), &m_cam, SLOT(open()));
    connect(&m_camTimer, SIGNAL(timeout()), &m_cam, SLOT(onTimeout()));
    connect(this, SIGNAL(capture()), &m_cam, SLOT(capture()));
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

void MainWindow::setScan(bool isscan)
{
    if(isscan) {
        ui->stackedWidget->setCurrentWidget(ui->page_auto);
        ui->slider_servo->setDisabled(true);
        m_camTimer.stop();
        connect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(onItemChanged(QListWidgetItem*)));
    } else {
        if(m_camThread.isRunning()) m_camTimer.start();
        setAutoly(ui->sw_autoOrMan->isToggled());
        disconnect(ui->listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onItemChanged(QListWidgetItem*)));
    }
}

void MainWindow::addList()
{
    int nIndex =0;
    QString path =QCoreApplication::applicationDirPath();
    while(1) {
        QString nm = QString("/image/%1.jpg").arg(nIndex);
        QString name =path + nm;
        if(access(name.toLatin1().data(),0) == -1) break;
        nIndex++;
        if(m_hash.find(name) != m_hash.end()) continue;
        //生成图像objPixmap
        QPixmap objPixmap(name);
        QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(W_ICONSIZE,H_ICONSIZE))),nm);
        //设置单元项的宽度和高度
        pItem->setSizeHint(QSize(W_ICONSIZE,W_ICONSIZE));
        ui->listWidget->insertItem(nIndex, pItem);
        m_hash[name] = pItem;
    }
}
