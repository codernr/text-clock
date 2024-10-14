#include <Arduino.h>
#include <FastLED.h>
#include "RTClib.h"
#include "config.h"

// #define ITERATOR
#define USE_RTC

CRGB leds[NUM_LEDS];

#ifndef USE_RTC
#include "debugtimer.h"
DebugTimer timer;
#else
#include "rtctimer.h"
RTCTimer timer;
#endif

#ifndef ITERATOR
#include "words.h"
Words program(timer);
#else
#include "iterator.h"
Iterator program(timer);
#endif

void setup() {
  Serial.begin(9600);

  delay( 3000 ); // power-up safety delay

  program.init();
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  program.update();
  FastLED.show();
}
