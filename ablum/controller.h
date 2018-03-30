#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "servo.h"
#include "infrared.h"
#include "camera.h"
#include <QObject>
#include <QTimer>

class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Mode mode READ mode WRITE setMode NOTIFY modeChanged)
public:
    explicit Controller(Camera *cam, QObject *parent = 0);
    enum Mode {
        MANUAL,
        ROUTING,
        AUTO,
        NONE
    };
    Q_ENUM(Mode)
    Mode mode() const { return m_mode; }

    int nowAngle() const;

signals:
    void modeChanged(const char m);
    void angleChanged(const int degree);

public slots:
    void init();
    void onSystem();
    void setMode(const char m);
    void setAngle(const int degree);
    void changeAngle(const int degree);
    void changeRouteTime(const int value);

private:
    Servo       *servo;
    Infrared    *infrared;
    Camera      *camera;
    QTimer      *m_tSystem;
    bool        m_capture;
    int         m_routeTime;
    volatile Mode m_mode;
};

#endif // CONTROLLER_H
