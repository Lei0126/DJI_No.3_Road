#include "camera.h"
#include <QFile>
#include <unistd.h>
#include <fcntl.h>
#include <QDebug>
#include <QCoreApplication>

#define Print()     qDebug() << " file:" << __FILE__ << " line:" <<__LINE__ <<" "

using namespace cv;

static QImage convert(Mat mat)
{
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }

    else if(mat.type() == CV_8UC3)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
}

Camera::Camera(QObject *parent) : QObject(parent)
{
    m_picNo =0;
    m_null.load(":/images/empty.jpg");
    m_image =m_null;
}

void Camera::capture()
{
    if(m_pic.empty())
        return;
    QString name;
    QString path = QCoreApplication::applicationDirPath();
    do{
        name =QString(path+"/image/%1.jpg").arg(m_picNo);
        m_picNo++;
    }while(access(name.toLatin1().data(), 0) != -1);
    imwrite(name.toLatin1().data(), m_pic);
}

void Camera::onTimeout()
{
    if(isOpened())
    {
        m_cam >> m_pic;
        if(m_pic.empty())
            m_image =m_null;
        else
            m_image =convert(m_pic);
        emit ready();
    }
}

bool Camera::isOpened() const
{
    return m_cam.isOpened();
}

bool Camera::open()
{
    bool res = m_cam.open(0);
    emit opened(res);
    return res;
}

void Camera::close()
{

}

void Camera::play()
{

}

void Camera::setIsScan(bool scan)
{
    m_isScan =scan;
}

bool Camera::isScan() const
{
    return m_isScan;
}
