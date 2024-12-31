#ifndef DUCKS_H
#define DUCKS_H

#include <Arduino.h>
#include <FastLED.h>
#include "config.h"

extern CRGB leds[NUM_LEDS];

const CRGB color0 = CRGB::Orange;
const CRGB color1 = CRGB::Gold;
const CRGB color2 = CRGB::Yellow;
const CRGB color3 = CRGB::Red;
const CRGB color4 = CRGB::Magenta;

const uint8_t duck0_color0[] PROGMEM = {
    3, 4, 6, 7, 17, 20, 27, 30, 39, 40, 41, 42, 43, 44,
    50, 57, 62, 70, 72, 73, 80, 87, 90, 91, 92, 93, 102,
    104, 105, 106, 107, 110, 111, 113, 126, 128, 135, 136
};

const uint8_t duck0_color1[] PROGMEM = {65, 66, 67, 68, 127};

const uint8_t duck1_color1[] PROGMEM = {
    2, 3, 4, 5, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27,
    31, 39, 41, 42, 43, 45, 46, 47, 49, 50, 51, 52, 53,
    54, 55, 57, 61, 62, 63, 64, 65, 66, 67, 68, 69, 74,
    75, 76, 77, 81, 82, 83, 90, 91, 92, 93, 97, 98, 99,
    101, 102, 113, 114, 116, 117, 123, 124, 125
};

const uint8_t duck1_color2[] PROGMEM = {96, 100};

const uint8_t duck2_color0[] PROGMEM = {10, 11};
const uint8_t duck2_color1[] PROGMEM = {
    0, 4, 5, 6, 7, 8, 9, 14, 16, 17, 18, 19, 20, 21, 22,
    24, 25, 26, 27, 28, 29, 31, 32, 44, 45, 46, 47, 48, 49
};
const uint8_t duck2_color3[] PROGMEM = {
    87, 103, 104, 105, 109, 110, 111, 112, 113,
    126, 127, 129, 130
};
const uint8_t duck2_color4[] PROGMEM = {38, 58, 61, 81};

class Ducks {
public:
    Ducks();
    void update(const DateTime now);

private:
    uint8_t second;
    uint8_t duck;
    void setDuck0();
    void setDuck1();
    void setDuck2();
};

Ducks::Ducks() {}

void Ducks::update(const DateTime now) {
    if (second == now.second()) return;

    second = now.second();

    if (second != 45) return;

    FastLED.clear();

    if (duck == 0) setDuck0();
    if (duck == 1) setDuck1();
    if (duck == 2) setDuck2();

    FastLED.show();

    duck = (duck + 1) % 3;
    
}

void Ducks::setDuck0() {
    for (uint8_t i = 0; i < sizeof(duck0_color0); i++) {
        leds[pgm_read_byte(&duck0_color0[i])] = color0;
    }

    for (uint8_t i = 0; i < sizeof(duck0_color1); i++) {
        leds[pgm_read_byte(&duck0_color1[i])] = color1;
    }
}

void Ducks::setDuck1() {
    for (uint8_t i = 0; i < sizeof(duck1_color1); i++) {
        leds[pgm_read_byte(&duck1_color1[i])] = color1;
    }

    for (uint8_t i = 0; i < sizeof(duck1_color2); i++) {
        leds[pgm_read_byte(&duck1_color2[i])] = color2;
    }
}

void Ducks::setDuck2() {
    for (uint8_t i = 0; i < sizeof(duck2_color0); i++) {
        leds[pgm_read_byte(&duck2_color0[i])] = color0;
    }

    for (uint8_t i = 0; i < sizeof(duck2_color1); i++) {
        leds[pgm_read_byte(&duck2_color1[i])] = color1;
    }

    for (uint8_t i = 0; i < sizeof(duck2_color3); i++) {
        leds[pgm_read_byte(&duck2_color3[i])] = color3;
    }

    for (uint8_t i = 0; i < sizeof(duck2_color4); i++) {
        leds[pgm_read_byte(&duck2_color4[i])] = color4;
    }
}

#endif