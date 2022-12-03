#pragma once

#include <Arduino.h>
#include <vector_uC.h>

#define Int32Vector TVector<uint32_t>

class LEDStrip {};

class APA102 : public LEDStrip
{
private:
  Int32Vector pixels;

public:
  APA102(int count) : pixels(count) {} 
  
  void init(void);
  uint16_t countPixels(void) {return pixels.Length();}

  void show(void);

  static uint32_t makeColor(uint32_t red, uint32_t grn, uint32_t blu);

  uint32_t& operator [] (int i) { return pixels[i]; }
};