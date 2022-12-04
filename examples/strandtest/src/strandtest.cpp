#include "APA102.h"

APA102 strip(10);

void setup() 
{
  Serial.begin(115200);
  strip.init();
}

void loop() 
{
  delay(20);
  uint32_t currTime = millis();
  uint16_t angle = (currTime / 20) % 360;
  uint8_t r = 100 * (1+sin(angle * 3.14 / 180.));
  uint8_t g = 100 * (1+sin((angle+120) * 3.14 / 180.));
  uint8_t b = 100 * (1+sin((angle+240) * 3.14 / 180.));

  // Some example procedures showing how to display to the pixels
  strip[0] = APA102::makeColor(r, g, b);
  strip.show();
}
