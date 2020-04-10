#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    150
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
CRGB color;
unsigned int t_min;
uint8_t minutes;
uint8_t hours;

#define UPDATES_PER_SECOND 10

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
  egy_a(h, m);
  ketto_a(h, m);
  harom_a(h, m);
  negy_a(h, m);
  ot_a(h, m);
  hat_a(h, m);
  het_a(h, m);
  egy_b(h, m);
  ketto_b(h, m);
  harom_b(h, m);
  negy_b(h, m);
  hat_b(h, m);
  het_b(h, m);
  nyolc(h, m);
  kilenc(h, m);
  tiz(h, m);
  tizenegy(h, m);
  tizenketto(h, m);
  del(h, m);
  ejfel(h, m);
  ora(h, m);
  perc(h, m);
  mult(h, m);
  mulva(h, m);
}

void egy_a(uint8_t h, uint8_t m) {
  if (m == 1 || m == 22 || m == 31 || m == 52) {
    leds[133] = color;
    leds[134] = color;
    leds[135] = color;
  }
}

void ketto_a(uint8_t h, uint8_t m) {
  if (m == 2 || m == 21 || m == 32 || m == 51) {
    leds[139] = color;
    leds[140] = color;
    leds[141] = color;
    leds[142] = color;
    leds[143] = color;
  }
}

void harom_a(uint8_t h, uint8_t m) {
  if (m == 3 || m == 20 || m == 33 || m == 50) {
    leds[132] = color;
    leds[131] = color;
    leds[130] = color;
    leds[129] = color;
    leds[128] = color;
  }
}

void negy_a(uint8_t h, uint8_t m) {
  if (m == 4 || m == 19 || m == 34 || m == 49) {
    leds[124] = color;
    leds[123] = color;
    leds[122] = color;
    leds[121] = color;
  }
}

void ot_a(uint8_t h, uint8_t m) {
  if (m == 5 || m == 18 || m == 35 || m == 48) {
    leds[109] = color;
    leds[110] = color;
  }
}

void hat_a(uint8_t h, uint8_t m) {
  if (m == 6 || m == 17 || m == 36 || m == 47) {
    leds[113] = color;
    leds[114] = color;
    leds[115] = color;
  }
}

void het_a(uint8_t h, uint8_t m) {
  if (m == 7 || m == 16 || m == 37 || m == 46) {
    leds[118] = color;
    leds[119] = color;
    leds[120] = color;
  }
}

bool num_b(uint8_t actual, uint8_t h, uint8_t m) {
  return ((h == actual && m > 7) || (h == (actual + 1) && m < 8) ||
    (h == (actual + 12) && m > 7) || (h == (actual + 13) && m < 8));
}

void egy_b(uint8_t h, uint8_t m) {
  if (num_b(0, h, m)) {
    leds[61] = color;
    leds[62] = color;
    leds[63] = color;
  }
}

void ketto_b(uint8_t h, uint8_t m) {
  if (num_b(1, h, m)) {
    leds[64] = color;
    leds[65] = color;
    leds[66] = color;
    leds[67] = color;
    leds[68] = color;
  }
}

void harom_b(uint8_t h, uint8_t m) {
  if (num_b(2, h, m)) {
    leds[60] = color;
    leds[59] = color;
    leds[58] = color;
    leds[57] = color;
    leds[56] = color;
  }
}

void negy_b(uint8_t h, uint8_t m) {
  if (num_b(3, h, m)) {
    leds[55] = color;
    leds[54] = color;
    leds[53] = color;
    leds[52] = color;
  }
}

/*
void OT_b(uint8_t h, uint8_t m) {
  if (num_b(4, h, m)) {
    leds[55] = color;
    leds[54] = color;
    leds[53] = color;
    leds[52] = color;
  }
}
*/

void hat_b(uint8_t h, uint8_t m) {
  if (num_b(5, h, m)) {
    leds[70] = color;
    leds[71] = color;
    leds[72] = color;
  }
}

void het_b(uint8_t h, uint8_t m) {
  if (num_b(6, h, m)) {
    leds[51] = color;
    leds[50] = color;
    leds[49] = color;
  }
}

void nyolc(uint8_t h, uint8_t m) {
  if (num_b(7, h, m)) {
    leds[37] = color;
    leds[38] = color;
    leds[39] = color;
    leds[40] = color;
  }
}

void kilenc(uint8_t h, uint8_t m) {
  if (num_b(8, h, m)) {
    leds[43] = color;
    leds[44] = color;
    leds[45] = color;
    leds[46] = color;
    leds[47] = color;
    leds[48] = color;
  }
}

void tiz(uint8_t h, uint8_t m) {
  if (num_b(9, h, m)) {
    leds[36] = color;
    leds[35] = color;
    leds[34] = color;
  }
}

void tizenegy(uint8_t h, uint8_t m) {
  if (num_b(10, h, m)) {
    leds[32] = color;
    leds[31] = color;
    leds[29] = color;
    leds[28] = color;
    leds[27] = color;
    leds[26] = color;
    leds[25] = color;
  }
}

void tizenketto(uint8_t h, uint8_t m) {
  if ((h == 11 && m > 7 && m < 53) || (h == 23 && m > 7 && m < 53)) {
    leds[14] = color;
    leds[15] = color;
    leds[16] = color;
    leds[17] = color;
    leds[18] = color;
    leds[19] = color;
    leds[20] = color;
    leds[21] = color;
    leds[22] = color;
    leds[23] = color;
  }
}

void del(uint8_t h, uint8_t m) {
  if ((h == 11 && m > 52) || (h == 12 && m < 8)) {
    leds[12]= color;
    leds[13]= color;
    leds[14]= color;
  }
}

void ejfel(uint8_t h, uint8_t m) {
  if ((h == 23 && m > 52) || (h == 0 && m < 8)) {
    leds[9]= color;
    leds[8]= color;
    leds[7]= color;
    leds[6]= color;
    leds[5]= color;
  }
}

void ora(uint8_t h, uint8_t m) {
  if ((h != 11 && h != 23 && m > 53) || (h != 0 && h != 12 && m < 8)) {
    leds[3]= color;
    leds[2]= color;
    leds[1]= color;
  }
}

void perc(uint8_t h, uint8_t m) {
  if (m != 0 && m != 15 && m != 30 && m != 45) {
    leds[108]= color;
    leds[107]= color;
    leds[106]= color;
    leds[105]= color;
  }
}

void mult(uint8_t h, uint8_t m) {
  if (m < 8 || (m > 15 && m < 23) || (m > 30 && m < 38) || (m > 45 && m < 53)) {
    leds[105]= color;
    leds[104]= color;
    leds[103]= color;
    leds[102]= color;
    leds[100]= color;
    leds[99]= color;
    leds[98]= color;
    leds[97]= color;
  }
}

void mulva(uint8_t h, uint8_t m) {
  if ((m > 7 && m < 15) || (m > 22 && m < 30) || (m > 37 && m < 45) || m > 52) {
    leds[87]= color;
    leds[88]= color;
    leds[89]= color;
    leds[90]= color;
    leds[91]= color;
  }
}
