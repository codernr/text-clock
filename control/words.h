#ifndef WORDS_H
#define WORDS_H

#include <Arduino.h>
#include <FastLED.h>
#include "RTClib.h"
#include "config.h"

extern CRGB leds[NUM_LEDS];
const CRGBPalette16 palette = RainbowColors_p;
uint8_t paletteIndex = 0;

class Words {
public:
    Words(Timer& timer);
    void init();
    void update();

private:
    Timer& timer;
    inline bool minuteActive(const uint8_t minute, const uint8_t m) __attribute__((always_inline));
    inline bool hourActive(const uint8_t hour, const uint8_t h, const uint8_t m) __attribute__((always_inline));
    void setPixels(const uint8_t h, const uint8_t m);
};

Words::Words(Timer& timer) : timer(timer) {}

void Words::init()
{
    timer.init();
}

void Words::update() {
    if (!timer.tick()) return;

    paletteIndex++;
    setPixels(timer.hour(), timer.minute());
}

void Words::setPixels(const uint8_t h, const uint8_t m) {
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        if (
            (i > 131 && i < 135 && minuteActive(1, m)) ||
            (i > 137 && i < 143 && minuteActive(2, m)) ||
            (i > 126 && i < 132 && minuteActive(3, m)) ||
            (i > 119 && i < 124 && minuteActive(4, m)) ||
            (i > 107 && i < 110 && minuteActive(5, m)) ||
            (i > 111 && i < 115 && minuteActive(6, m)) ||
            (i > 116 && i < 120 && minuteActive(7, m)) ||

            (i > 103 && i < 108 && m % 15 != 0) ||
            (i > 100 && i < 104 && m % 15 > 0 && m % 15 < 8) ||
            (i > 95 && i < 100 && m % 15 > 0 && m % 15 < 8) ||
            (i > 85 && i < 91 && m % 15 > 7 && m % 15 != 0) ||
            (i > 92 && i < 96 && m > 22 && m < 38) ||
            (i > 78 && i < 84 && m > 37 && m < 53) ||
            (i > 72 && i < 79 && m % 30 > 7 && m % 30 < 23) ||

            (i > 59 && i < 63 && hourActive(1, h, m)) ||
            (i > 62 && i < 68 && hourActive(2, h, m)) ||
            (i > 54 && i < 60 && hourActive(3, h, m)) ||
            (i > 50 && i < 55 && hourActive(4, h, m)) ||
            (i > 21 && i < 24 && hourActive(5, h, m)) ||
            (i > 68 && i < 72 && hourActive(6, h, m)) ||
            (i > 47 && i < 51 && hourActive(7, h, m)) ||
            (i > 35 && i < 41 && hourActive(8, h, m)) ||
            (i > 41 && i < 48 && hourActive(9, h, m)) ||
            (i > 32 && i < 36 && hourActive(10, h, m)) ||
            (i > 23 && i < 32 && hourActive(11, h, m)) ||
            (i > 11 && i < 22 && ((h == 11 || h == 23) && m <= 52 && m > 7))  ||

            (i > 8 && i < 12 && ((h == 11 && m > 52) || (h == 12 && m < 8))) ||
            (i > 3 && i < 9 && ((h == 23 && m > 52) || (h == 0 && m < 8))) ||
            (i >=0 && i < 3 && ((h != 11 && h != 23 && m > 53) || (h != 0 && h != 12 && m < 8)))
        )
        leds[i].setHSV(paletteIndex, 255, 255);

        else leds[i] = CRGB::Black;
    }
}

bool Words::minuteActive(const uint8_t minute, const uint8_t m) {
    return m % 15 == minute || m % 15 == 15 - minute;
}

bool Words::hourActive(const uint8_t hour, const uint8_t h, const uint8_t m) {
    return (h % 12 == hour - 1 && m > 7) || (h % 12 == hour && m < 8);
}

#endif // WORDS_H