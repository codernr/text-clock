#ifndef RULES_H
#define RULES_H

#include <stdint.h>

#include <Arduino.h>
#include <FastLED.h>

class Word
{
public:
    Word(const String &content, uint8_t start, CRGB *leds)
        : content(content), length(static_cast<uint8_t>(content.length())), start(start), leds(leds) {}
    
    virtual bool isActive(uint8_t h, uint8_t m) const = 0;
    
    virtual ~Word() {}

    void update(uint8_t h, uint8_t m, CRGB color)
    {
        if (isActive(h, m))
        {
            Serial.print(" " + content);
            for (uint8_t i = 0; i < length; ++i)
            {
                leds[start + i] = color;
            }
        }
    }

protected:
    String content;
    uint8_t length;
    uint8_t start;
    CRGB *leds;
};;

class MinuteWord : public Word
{
public:
    MinuteWord(uint8_t minute, const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds), minute_(minute) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return m % 15 == minute_ || m % 15 == 15 - minute_;
    }

private:
    uint8_t minute_;
};

class HourWord : public Word
{
public:
    HourWord(uint8_t hour, const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds), hour_(hour) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return (h % 12 == hour_ - 1 && m > 7) || (h % 12 == hour_ && m < 8);
    }

private:
    uint8_t hour_;
};

class NoonWord : public Word
{
public:
    NoonWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return (h == 11 && m > 52) || (h == 12 && m < 8);
    }
};

class MidnightWord : public Word
{
public:
    MidnightWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return (h == 23 && m > 52) || (h == 0 && m < 8);
    }
};

class HourTextWord : public Word
{
public:
    HourTextWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return (h != 11 && h != 23 && m > 53) || (h != 0 && h != 12 && m < 8);
    }
};

class MinuteTextWord : public Word
{
public:
    MinuteTextWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return m % 15 != 0;
    }
};

class QuarterPrefixWord : public Word
{
public:
    QuarterPrefixWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return m > 37 && m < 53;
    }
};

class QuarterWord : public Word
{
public:
    QuarterWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return m % 30 > 7 && m % 30 < 23;
    }
};

class HalfWord : public Word
{
public:
    HalfWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return m > 22 && m < 38;
    }
};

class PastWord : public Word
{
public:
    PastWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return (m % 15 > 0 && m % 15 < 8);
    }
};

class ToWord : public Word
{
public:
    ToWord(const String &content, uint8_t start, CRGB *leds)
        : Word(content, start, leds) {}

    bool isActive(uint8_t h, uint8_t m) const override
    {
        return m % 15 > 7 && m % 15 != 0;
    }
};

#endif // RULES_H