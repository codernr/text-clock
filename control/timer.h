#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer
{
    public:
        virtual void init();
        virtual bool tick() = 0;
        virtual uint8_t hour() = 0;
        virtual uint8_t minute() = 0;
        virtual uint8_t second() = 0;
};

#endif