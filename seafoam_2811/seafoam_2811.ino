#include "FastLED.h"        // https://github.com/FastLED/FastLED

// LED Strip
#define NUM_LEDS 100
#define NUM_CHANNELS 3
#define DATA_PIN 13
#define MAX_BRIGHTNESS 30

// LED Array
CRGB leds[NUM_LEDS*4];

void setup() {
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

  // Initialize all LEDs to black
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0,0,0);
  }    
  FastLED.show();
}

void loop() {
  rainbowCycle(20);
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< NUM_LEDS; i++) {
//      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
//   return strip.Color(50+((WheelPos * 3)/3), 50+((255 - WheelPos * 3)/3), 50);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
//   return strip.Color(50+((255 - WheelPos * 3)/3), 50, 50+((WheelPos * 3)/3));
  } else {
   WheelPos -= 170;
//   return strip.Color(50, 50+((WheelPos * 3)/3), 50+((255 - WheelPos * 3)/3));
  }
}

