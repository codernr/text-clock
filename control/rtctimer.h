#ifndef DEBUGTIMER_h
#define DEBUGTIMER_h

#include <Arduino.h>
#include "RTClib.h"
#include "timer.h"

#define INTERVAL 200

RTC_DS3231 rtc;

class RTCTimer : public Timer
{
    public:
        RTCTimer();
        void init();
        bool tick();
        uint8_t hour();
        uint8_t minute();
    private:
        DateTime previousNow;
};

RTCTimer::RTCTimer() {}

void RTCTimer::init()
{
    rtc.begin();
    if (rtc.lostPower()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    previousNow = rtc.now() - TimeSpan(0, 0, 1, 0);
}

bool RTCTimer::tick()
{
    DateTime now = rtc.now();
    if (previousNow.minute() == now.minute()) return false;

    previousNow = now;
    return true;
}

uint8_t RTCTimer::hour()
{
    return previousNow.hour();
}

uint8_t RTCTimer::minute()
{
    return previousNow.minute();
}

#endif