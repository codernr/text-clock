#include <Arduino.h>
#include <FastLED.h>
#include "RTClib.h"
#include "config.h"
#include "rtctimer.h"
#include "words.h"
#include "ducks.h"

CRGB leds[NUM_LEDS];
RTCTimer timer;
Words program(timer);
Ducks ducks(timer);

void setup() {
  Serial.begin(9600);

  delay( 3000 ); // power-up safety delay

  timer.init();
  
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  timer.tick();
  program.update();
  ducks.update();
}
