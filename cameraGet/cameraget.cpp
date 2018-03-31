#include "cameraget.h"
#include <wiringPi.h>
#include <sensor.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <string>
#include "ui_cameraget.h"
bool servo_mode=TRUE;
bool servo_period_mode=FALSE;
bool servo_infrared_mode=TRUE;
unsigned int manual_degree=0;
unsigned int servo_rotate_interval=250;
cameraGet::cameraGet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cameraGet)
{
    ui->setupUi(this);
    gpio_init();

    cam     = NULL;
    timer   = new QTimer(this);
    imag    = new QImage();



    /*信号和槽*/
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));  // 时间到，读取当前摄像头信息
    connect(ui->open, SIGNAL(clicked()), this, SLOT(opencamera()));
    connect(ui->pic, SIGNAL(clicked()), this, SLOT(takingPictures()));
    connect(ui->savepic, SIGNAL(clicked()), this, SLOT(savingPictures()));
    connect(ui->openpic, SIGNAL(clicked()), this, SLOT(openningPictures()));
    connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closecamera()));
}

/******************************
********* 打开摄像头 ***********
*******************************/
void cameraGet::opencamera()
{
    cam = cvCreateCameraCapture(0);//打开摄像头，从摄像头中获取视频

    timer->start(30);              // 开始计时，超时则发出timeout()信号
}

/*********************************
********* 读取摄像头信息 ***********
**********************************/
void cameraGet::readFarme()
{

    if(servo_mode){
    int servo_state = 0;
    unsigned char infrared_state = infrared_check();
    if(servo_infrared_mode)
    servo_state=servo_automate(infrared_state);
    timer->stop();
    if(servo_period_mode)
    {
      servo_rotate_period(servo_rotate_interval,servo_state);
    }
    if(servo_state!=0){
        cameraGet::takingPictures();
        delay(50);
        }
    }
    else{
     servo_manual(manual_degree);
     delay(100);
     }
     frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧
    QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();// 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    ui->label->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
    delay(30);//
    timer->start();
}

/*************************
********* 拍照 ***********
**************************/
void cameraGet::takingPictures()
{
    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧

    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    cvConvertImage(frame,frame,CV_CVTIMG_SWAP_RB);//rgb convert to bgr
    QImage image((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);
    ui->label_2->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label_2上
    //delay(20);
    const QPixmap *pixmap=ui->label_2->pixmap();
    QString strDir = QCoreApplication::applicationDirPath() + "/ScreenShot";
    QDir dir(strDir);
    if(!dir.exists())
    {
      dir.mkdir(strDir);
    }
    QString fileName = strDir + "/Monitor" + QDateTime::currentDateTime().toString("yyyyMMddHHmmss") + ".jpg";
    //默认保存路径为当前应用程序路径下的ScreenShot文件夹，如果没有就新建该文件夹
    if(pixmap)
    {
    pixmap->save(fileName);
    }
}
/*******************************
******savingPictures************/
void cameraGet::savingPictures()
{
        const QPixmap *pixmap=ui->label_2->pixmap();
    //默认保存路径为当前应用程序路径下的ScreenShot文件夹，如果没有就新建该文件夹
        QString strDir = QCoreApplication::applicationDirPath() + "/ScreenShot";
        QDir dir(strDir);
        if(!dir.exists())
        {
            dir.mkdir(strDir);
        }
        QString strFile = strDir + "/Monitor" + QDateTime::currentDateTime().toString("yyyyMMddHHmmss") + ".jpg";
        timer->stop();
        QString fileName=QFileDialog::getSaveFileName(this,"保存图片",strFile,"JPEG (*.jpg *.jpeg);;BMP (*.bmp);;PNG (*.png)");
        if(!fileName.isNull())
        {
            pixmap->save(fileName);
        }
        timer->start(25);              // 开始计时，超时则发出timeout()信号
}

/*******************************
**********openningPictures******/
void cameraGet::openningPictures()
{
    ui->label_2->clear();//先清除label内容
        //打开图片操作
        QString fileName = QFileDialog::getOpenFileName(
                    this, tr("open image file"),
                    "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

        if(fileName.isEmpty())
        {
            QMessageBox mesg;
            mesg.warning(this,"警告","打开图片失败!");
            return;
        }
        else
        {
            QImage img(fileName);
            img=img.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio);//Qt::KeepAspectRatio自适应大小，不变形
            ui->label_2->setPixmap(QPixmap::fromImage(img));
            if(img.isNull())
            {
                QMessageBox::information(this,"信息","打开文件失败");
            }
        }
}
/*******************************
***关闭摄像头，释放资源，必须释放***
********************************/
void cameraGet::closecamera()
{
    timer->stop();         // 停止读取数据。

    cvReleaseCapture(&cam);//释放内存；
}

cameraGet::~cameraGet()
{
    delete ui;
}

void cameraGet::on_pushButton_clicked()
{
  servo_infrared_mode=!servo_infrared_mode;
}

void cameraGet::on_pushButton_2_clicked()
{
  servo_period_mode =!servo_period_mode;
}

void cameraGet::on_pushButton_3_clicked()
{
    servo_mode=!servo_mode;
}

void cameraGet::on_degreeSlider_valueChanged(int value)
{
    int temp=value;
    manual_degree=temp;
}

void cameraGet::on_verticalSlider_valueChanged(int value)
{
    int temp1=100-value;
    servo_rotate_interval=temp1*5;
}
