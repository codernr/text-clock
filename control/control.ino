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
CRGB color;
unsigned int t_min;
uint8_t minutes;
uint8_t hours;

Word* words[] = {
  new MinuteWord(1, String("egy"), 132, leds),
  new MinuteWord(2, String("ketto"), 138, leds),
  new MinuteWord(3, String("harom"), 127, leds),
  new MinuteWord(4, String("negy"), 120, leds),
  new MinuteWord(5, String("ot"), 108, leds),
  new MinuteWord(6, String("hat"), 112, leds),
  new MinuteWord(7, String("het"), 117, leds),
  new MinuteTextWord(String("perc"), 104, leds),
  new PastWord(String("cel"), 101, leds),
  new PastWord(String("mult"), 96, leds),
  new ToWord(String("mulva"), 86, leds),
  new HalfWord(String("fel"), 93, leds),
  new QuarterPrefixWord(String("harom"), 79, leds),
  new QuarterWord(String("negyed"), 73, leds),
  new HourWord(1, String("egy"), 60, leds),
  new HourWord(2, String("ketto"), 64, leds),
  new HourWord(3, String("harom"), 55, leds),
  new HourWord(4, String("negy"), 51, leds),
  new HourWord(5, String("ot"), 22, leds),
  new HourWord(6, String("hat"), 69, leds),
  new HourWord(7, String("het"), 48, leds),
  new HourWord(8, String("nyolc"), 36, leds),
  new HourWord(9, String("kilenc"), 42, leds),
  new HourWord(10, String("tiz"), 33, leds),
  new HourWord(11, String("tizenegy"), 24, leds),
  new HourWord(12, String("tizenketto"), 12, leds),
  new NoonWord(String("del"), 9, leds),
  new MidnightWord(String("ejfel"), 4, leds),
  new HourTextWord(String("ora"), 0, leds),
};

void setup() {
  Serial.begin(9600);
  delay( 3000 ); // power-up safety delay
  t_min = 0;
  color = CRGB::Blue;
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  if (t_min == 24 * 60) {
    t_min = 0;
  }
  
  hours = (t_min / 60);
  minutes = (t_min - hours * 60);

  FastLED.clear();
  update(hours, minutes);
  FastLED.show();
  t_min = t_min + 1;
  FastLED.delay(1000);
}

void update(uint8_t h, uint8_t m) {
  //Serial.print("T[" + String(h) + ":" + String(m) + "]");
  for (Word* word : words) {
    word->update(h, m, color);
  }
  //Serial.println();
}
