#pragma once

#include <Arduino.h>
#include <APA102.h>

// arguments = {0..1}
uint32_t HSVtoRGB(float hue, float saturation, float value);