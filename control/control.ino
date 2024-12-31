#include <Arduino.h>
#include <FastLED.h>
#include "RTClib.h"
#include "config.h"
#include "words.h"
#include "ducks.h"

CRGB leds[NUM_LEDS];
RTC_DS3231 rtc;

Words words;
Ducks ducks;

void setup()
{
  Serial.begin(9600);

  delay(3000); // power-up safety delay

  initRtc();

  randomSeed(analogRead(0));

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void initRtc()
{
  rtc.begin();
  if (rtc.lostPower())
  {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop()
{
  words.update(rtc.now());
  ducks.update(rtc.now());
}
