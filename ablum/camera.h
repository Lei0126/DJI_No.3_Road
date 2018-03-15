#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QTimer>
#include <opencv2/opencv.hpp>
#include <QImage>


class Camera : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isScan READ isScan WRITE setIsScan NOTIFY isScanChanged)
public:
    explicit Camera(QObject *parent = nullptr);
    Q_INVOKABLE bool isOpened() const;
    Q_INVOKABLE void close();
    Q_INVOKABLE void play();
    Q_INVOKABLE bool isScan() const;
    Q_INVOKABLE void setIsScan(bool scan);

    QImage              m_image;

signals:
    void isScanChanged(const bool scan);
    void ready();
    void opened(const bool b);

public slots:
    bool open();
    void capture();
    void onTimeout();

private:
    cv::VideoCapture    m_cam;
    cv::Mat             m_pic;
    QImage              m_null;
    bool                m_isScan;
    int                 m_picNo;
};

#endif // CAMERA_H
