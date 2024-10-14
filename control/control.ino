#include <Arduino.h>
#include <FastLED.h>
#include "config.h"

#define TESTING

CRGB leds[NUM_LEDS];

#ifndef TESTING
#include "words.h"
Words program;
#else
#include "iterator.h"
Iterator program;
#endif

void setup() {
  Serial.begin(9600);
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  program.update();
  FastLED.show();
}
