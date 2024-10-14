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
  new MinuteWord(1, 132, 3, leds), // "egy" has length 3
  new MinuteWord(2, 138, 5, leds), // "ketto" has length 5
  new MinuteWord(3, 127, 5, leds), // "harom" has length 5
  new MinuteWord(4, 120, 4, leds), // "negy" has length 4
  new MinuteWord(5, 108, 2, leds), // "ot" has length 2
  new MinuteWord(6, 112, 3, leds), // "hat" has length 3
  new MinuteWord(7, 117, 3, leds), // "het" has length 3
  new MinuteTextWord(104, 4, leds), // "perc" has length 4
  new PastWord(101, 3, leds), // "cel" has length 3
  new PastWord(96, 4, leds), // "mult" has length 4
  new ToWord(86, 5, leds), // "mulva" has length 5
  new HalfWord(93, 3, leds), // "fel" has length 3
  new QuarterPrefixWord(79, 5, leds), // "harom" has length 5
  new QuarterWord(73, 6, leds), // "negyed" has length 6
  new HourWord(1, 60, 3, leds), // "egy" has length 3
  new HourWord(2, 64, 5, leds), // "ketto" has length 5
  new HourWord(3, 55, 5, leds), // "harom" has length 5
  new HourWord(4, 51, 4, leds), // "negy" has length 4
  new HourWord(5, 22, 2, leds), // "ot" has length 2
  new HourWord(6, 69, 3, leds), // "hat" has length 3
  new HourWord(7, 48, 3, leds), // "het" has length 3
  new HourWord(8, 36, 5, leds), // "nyolc" has length 5
  new HourWord(9, 42, 6, leds), // "kilenc" has length 6
  new HourWord(10, 33, 3, leds), // "tiz" has length 3
  new HourWord(11, 24, 8, leds), // "tizenegy" has length 8
  new HourWord(12, 12, 10, leds), // "tizenketto" has length 10
  new NoonWord(9, 3, leds), // "del" has length 3
  new MidnightWord(4, 5, leds), // "ejfel" has length 5
  new HourTextWord(0, 3, leds), // "ora" has length 3
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
