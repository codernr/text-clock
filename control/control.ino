#include <FastLED.h>
#include "words.h"

#define LED_PIN     5
#define NUM_LEDS    150
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 10

CRGB leds[NUM_LEDS];
CRGB color;
unsigned int t_min;
uint8_t minutes;
uint8_t hours;

Word* words[] = {
  new MinuteWord(1, "egy", 132, leds),
  new MinuteWord(2, "ketto", 138, leds),
  new MinuteWord(3, "harom", 127, leds),
  new MinuteWord(4, "negy", 120, leds),
  new MinuteWord(5, "ot", 108, leds),
  new MinuteWord(6, "hat", 112, leds),
  new MinuteWord(7, "het", 117, leds),
  new HourWord(1, "egy", 60, leds),
  new HourWord(2, "ketto", 64, leds),
  new HourWord(3, "harom", 55, leds),
  new HourWord(4, "negy", 51, leds),
  new HourWord(5, "ot", 22, leds),
  new HourWord(6, "hat", 69, leds),
  new HourWord(7, "het", 48, leds),
  new HourWord(8, "nyolc", 36, leds),
  new HourWord(9, "kilenc", 42, leds),
  new HourWord(10, "tiz", 33, leds),
  new HourWord(11, "tizenegy", 24, leds),
  new HourWord(12, "tizenketto", 12, leds),
  new NoonWord("del", 9, leds),
  new MidnightWord("ejfel", 4, leds),
  new HourTextWord("ora", 0, leds),
  new MinuteTextWord("perc", 104, leds),
  new PastWord("cel", 101, leds),
  new QuarterPrefixWord("harom", 79, leds),
  new QuarterWord("negyed", 73, leds),
  new HalfWord("fel", 93, leds),
  new PastWord("mult", 96, leds),
  new ToWord("mulva", 86, leds)
};

void setup() {
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
  for (Word* word : words) {
    word->update(h, m);
  }
}
