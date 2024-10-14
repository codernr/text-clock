#ifndef ITERATOR_H
#define ITERATOR_H

#include <Arduino.h>
#include <FastLED.h>
#include "config.h"

#define INTERVAL 300

extern CRGB leds[NUM_LEDS];

class Iterator {
public:
    Iterator();
    void update();

private:
    unsigned long previousMillis;
    uint8_t i;
};

Iterator::Iterator() : previousMillis(0UL), i(0) {}

void Iterator::update()
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis < INTERVAL) return;
    previousMillis = currentMillis;

    FastLED.clear();
    leds[i] = CRGB::Blue;
    FastLED.show();

    i = (i + 1) % NUM_LEDS;
}

#endif