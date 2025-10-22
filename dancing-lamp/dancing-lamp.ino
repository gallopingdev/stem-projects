#include <FastLED.h>
#define NUM_LEDS 20
CRGB leds[NUM_LEDS];

const int LED_PIN = 3;

void setup() {
  
  FastLED.addLeds<WS2812, LED_PIN>(leds, NUM_LEDS);

}

void loop() {
  
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[3] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[4] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[5] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[6] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[7] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[8] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[9] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[10] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[11] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[12] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[13] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[14] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[15] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[16] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[17] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[18] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);
  leds[19] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);

  for (int i = 0; i <= 19; i++){
    leds[i] = CRGB::DarkBlue;
    FastLED.show();
    delay(40);
  }
}
