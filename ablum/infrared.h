#ifndef INFRARED_H
#define INFRARED_H

#include <QObject>

class Infrared : public QObject
{
    Q_OBJECT
public:
    explicit Infrared(QObject *parent = 0);

    enum Direction{
        NONE,
        RIGHT,
        FRONT,
        LEFT
    };

    Q_ENUM(Direction)

    Direction check();
signals:

public slots:

private:
    void init();
};

#endif // INFRARED_H
