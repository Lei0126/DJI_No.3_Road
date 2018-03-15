#include "servo.h"

Servo::Servo(QObject *parent) : QObject(parent)
{

}

const int Servo::nowAngle()
{
    return m_nowAngle;
}

void Servo::setNowAngle(const int angle)
{
    if(m_nowAngle != angle) {
        m_nowAngle = angle;
        emit nowAngleChanged(angle);
    }
}
