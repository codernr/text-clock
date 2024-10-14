#include <Arduino.h>
#include <FastLED.h>
#include "config.h"
#include "words.h"

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  updateWords();
  FastLED.show();
}
