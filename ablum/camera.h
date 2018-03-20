#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <QImage>


class Camera : public QObject
{
    Q_OBJECT
public:
    explicit Camera(QObject *parent = nullptr);
    Q_INVOKABLE bool isOpened() const;
    Q_INVOKABLE void close();

    QImage              m_image;
    QString             m_firstPath;
    QString             m_fullPath;
signals:
    void ready();
    void captured(const QString name);
    void opened(const bool b);

public slots:
    void open();
    void play();
    void capture();
    void onTimeout();

private:
    cv::VideoCapture    m_cam;
    cv::Mat             m_pic;
    QTimer              *m_tPlay;
    QImage              m_null;

};

#endif // CAMERA_H
