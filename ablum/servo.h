#ifndef SERVO_H
#define SERVO_H

#include <QObject>
#include <QTimer>

class Servo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int nowAngle READ nowAngle WRITE setNowAngle NOTIFY nowAngleChanged)
public:
    explicit Servo(QObject *parent = nullptr);
    ~Servo();
    Q_INVOKABLE const int nowAngle();
    Q_INVOKABLE void setNowAngle(const int angle);

signals:
    void nowAngleChanged(const int &angle);
    void completed();

public slots:
    void onTimeout();

private:
    void init();
    void rotato(const int angle);
    QTimer  m_finishTimer;
    int     m_nowAngle;
};

#endif // SERVO_H
