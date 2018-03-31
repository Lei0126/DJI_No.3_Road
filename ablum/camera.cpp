#include "camera.h"
#include <QFile>
#include <unistd.h>
#include <fcntl.h>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include <QDateTime>

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
    m_null.load(":/images/empty.jpg");
    m_firstPath = QCoreApplication::applicationDirPath() + "/image";
    m_fullPath = m_firstPath + "/" + QDateTime::currentDateTime().toString(tr("yy_MM_dd"));
    QDir dir(m_fullPath);
    if(!dir.exists())
        dir.mkpath(m_fullPath);
    m_image =m_null;
}

void Camera::capture()
{
    //Print() << QDateTime::currentDateTime().toString(tr("mm:ss:zzz"));
    QString name = m_fullPath + QString("/%1.jpg").arg(QDateTime::currentDateTime().toString(tr("hh.mm.ss.zzz")));
    if(!m_pic.empty()) imwrite(name.toLatin1().data(), m_pic);;
    emit captured(name);
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

void Camera::open()
{
    bool res = m_cam.open(0);
    emit opened(res);
    if(res) {
        m_tPlay = new QTimer();
        m_tPlay->start(40);
        Print() << "camera thread begin!";
        connect(m_tPlay, SIGNAL(timeout()), this, SLOT(play()));
    }
}

void Camera::close()
{

}

void Camera::play()
{
    m_cam >> m_pic;
    if(m_pic.empty())
        m_image =m_null;
    else
        m_image =convert(m_pic);
    emit ready();
}
