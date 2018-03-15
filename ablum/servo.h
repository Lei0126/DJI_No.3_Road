#ifndef SERVO_H
#define SERVO_H

#include <QObject>

class Servo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int nowAngle READ nowAngle WRITE setNowAngle NOTIFY nowAngleChanged)
public:
    explicit Servo(QObject *parent = nullptr);
    Q_INVOKABLE const int nowAngle();
    Q_INVOKABLE void setNowAngle(const int angle);

signals:
    void nowAngleChanged(const int &angle);

public slots:

private:
    int     m_nowAngle;
};

#endif // SERVO_H
