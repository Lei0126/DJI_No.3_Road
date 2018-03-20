#include "infrared.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <wiringPi.h>

#define infrared1_pin 27
#define infrared2_pin 28
#define infrared3_pin 29

#define STILL 0
#define ROTATE 1

Infrared::Infrared(QObject *parent) : QObject(parent)
{
    init();
}

Infrared::Direction Infrared::check()
{
    if(digitalRead(infrared1_pin)) return RIGHT;
    if(digitalRead(infrared2_pin)) return FRONT;
    if(digitalRead(infrared3_pin)) return LEFT;
    return NONE;
}

void Infrared::init()
{
    pinMode(infrared1_pin,INPUT);
    pinMode(infrared2_pin,INPUT);
    pinMode(infrared3_pin,INPUT);
}
