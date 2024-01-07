/*
 Name:		TEST_FastLED_WS2812B.ino
 Created:	1/2/2024 5:34:04 PM
 Author:	Micro
*/

#include <FastLED.h>
#define COLOUR_ORDER GRB
#define CHIPSET WS2812B
#define NUM_LEDS 144
#define DATA_PIN 2
#define VOLTS 5
#define MAX_AMPS 2000
#define BRIGHTNESS 255

CRGB leds[NUM_LEDS];

// the setup function runs once when you press reset or power the board
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOUR_ORDER>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
  delay(1000);
  Serial.println("Hello, FastLED Started");
}

// the loop function runs over and over again until power down or reset
void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255, 0, 0);
  }
  FastLED.show();
  delay(1000);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 255, 0);
  }
  FastLED.show();
  delay(1000);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 255);
  }
  FastLED.show();
  delay(1000);
}
