#pragma once

#include <color-utils.h>

// arguments = {0..1}
uint32_t HSVtoRGB(float hue, float saturation, float value)
{
  float Hprime = hue * 6.0;   //    / (1024.0 / 6.0);
  float chroma = val * sat;

  int iH = Hprime / 2;
  float Hmod2 = Hprime - iH * 2;
  float X = chroma * (1.0 - fabs(Hmod2 - 1.0));

  float rp = 0;
  float gp = 0;
  float bp = 0;

  if(Hprime < 1.0)      {rp = chroma; gp = X; bp = 0;}
  else if(Hprime < 2.0) {rp = X; gp = chroma; bp = 0;}
  else if(Hprime < 3.0) {rp = 0; gp = chroma; bp = X;}
  else if(Hprime < 4.0) {rp = 0; gp = X; bp = chroma;}
  else if(Hprime < 5.0) {rp = X; gp = 0; bp = chroma;}
  else                  {rp = chroma; gp = 0; bp = X;}

  float m = val - chroma;
  float red = 256 * (rp + m);
  float green = 256 * (gp + m);
  float blue = 256 * (bp + m);

  return APA102::makeColor(red, green, blue);
}
