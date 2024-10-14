#include <Arduino.h>
#include <FastLED.h>
#include "words.h"

#define LED_PIN     5
#define NUM_LEDS    144
#define BRIGHTNESS  32
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 10

CRGB leds[NUM_LEDS];
unsigned int t_min;
uint8_t minutes;
uint8_t hours;

void setup() {
  Serial.begin(9600);
  delay( 3000 ); // power-up safety delay
  t_min = 0;
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  if (t_min == 24 * 60) {
    t_min = 0;
  }
  
  hours = (t_min / 60);
  minutes = (t_min - hours * 60);

  update(hours, minutes);
  FastLED.show();
  t_min = t_min + 1;
  FastLED.delay(1000);
}

void update(uint8_t h, uint8_t m) {
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = getPixel(i, h, m);
  }
}
