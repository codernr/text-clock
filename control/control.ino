#include <Arduino.h>
#include <FastLED.h>
#include "RTClib.h"
#include "config.h"

#define TESTING

CRGB leds[NUM_LEDS];
RTC_DS3231 rtc;

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

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  program.update();
  FastLED.show();
}
