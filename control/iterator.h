#ifndef ITERATOR_H
#define ITERATOR_H

#include <Arduino.h>
#include <FastLED.h>
#include "config.h"
#include "timer.h"

#define INTERVAL 300

extern CRGB leds[NUM_LEDS];

class Iterator {
public:
    Iterator(Timer& timer);
    void init();
    void update();

private:
    Timer& timer;
    uint8_t i;
};

Iterator::Iterator(Timer& timer) : timer(timer), i(0) {}

void Iterator::init()
{
    timer.init();
}

void Iterator::update()
{
    if (!timer.tick()) return;

    FastLED.clear();
    leds[i] = CRGB::Blue;
    FastLED.show();

    i = (i + 1) % NUM_LEDS;
}

#endif