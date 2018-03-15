#ifndef cameraGET_H
#define cameraGET_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QImage>
#include <QMessageBox>
#include <QTimer>
#include <QFileDialog>
#include <qcursor.h>
#include <QDir>
#include <QDateTime>
#include <QClipboard>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <stdio.h>
#include <string>
#include <opencv/highgui.h>  //包含opencv库头文件
#include <opencv/cv.h>

using namespace cv;
namespace Ui {
    class cameraGet;
}

class cameraGet : public QMainWindow
{
    Q_OBJECT

public:
    explicit cameraGet(QWidget *parent = 0);
    ~cameraGet();

private slots:
    void opencamera();      // 打开摄像头
    void readFarme();       // 读取当前帧信息
    void closecamera();     // 关闭摄像头。
    void takingPictures();  // 拍照
    void savingPictures();
    void openningPictures();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_degreeSlider_valueChanged(int value);
    void on_verticalSlider_valueChanged(int value);

private:
    Ui::cameraGet *ui;
    QTimer    *timer;
    QImage    *imag;
    CvCapture *cam;// 视频获取结构， 用来作为视频获取函数的一个参数
    IplImage  *frame;//申请IplImage类型指针，就是申请内存空间来存放每一帧图像
};

#endif // cameraGET_H

