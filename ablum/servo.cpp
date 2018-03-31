#include "servo.h"
#include <math.h>
#include <wiringPi.h>
#include <softPwm.h>

#define servo_pin 1
#define RANGE 200

Servo::Servo(QObject *parent) : QObject(parent)
{
    m_nowAngle =90;
    m_finishTimer.setSingleShot(true);
    init();
    connect(&m_finishTimer, SIGNAL(timeout()), SLOT(onTimeout()));
}

Servo::~Servo()
{
    pwmWrite(servo_pin, 0);
}

const int Servo::nowAngle()
{
    return m_nowAngle;
}

void Servo::setNowAngle(const int angle, bool capture)
{
    if(m_nowAngle != angle) {
        rotato(angle);
        if(capture) {
            m_finishTimer.stop();
            int t = abs(angle-m_nowAngle)*5;
            t = t > 50 ? t : 50;
            m_finishTimer.start(t);
        }
        m_nowAngle = angle;
        emit nowAngleChanged(angle);
    }
}

void Servo::onTimeout()
{
    emit completed();
}

void Servo::init()
{
    //softPwmCreate(servo_pin,15,RANGE);
    pinMode(servo_pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(1920);
    pwmSetRange(200);

    rotato(m_nowAngle);
}

void Servo::rotato(const int angle)
{
    int servo_degree = 0;
    servo_degree = angle*20/180+5;
    if(servo_degree < 5) servo_degree = 5;
    else if(servo_degree > 25) servo_degree = 25;
    //softPwmWrite(servo_pin,servo_degree);
    pwmWrite(servo_pin, servo_degree);
}
