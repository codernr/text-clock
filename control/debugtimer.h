#ifndef DEBUGTIMER_h
#define DEBUGTIMER_h

#include <Arduino.h>
#include "timer.h"

#define INTERVAL 250

class DebugTimer : public Timer
{
    public:
        DebugTimer();
        void init();
        bool tick();
        uint8_t hour();
        uint8_t minute();
    private:
        unsigned long previousMillis;
        uint16_t i;
};

DebugTimer::DebugTimer() : previousMillis(0UL), i(0) {}

void DebugTimer::init() {}

bool DebugTimer::tick()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis < INTERVAL) return false;
    previousMillis = currentMillis;
    i = (i + 1) % 1440;

    return true;
}

uint8_t DebugTimer::hour()
{
    return i / 60;
}

uint8_t DebugTimer::minute()
{
    return i % 60;
}

#endif