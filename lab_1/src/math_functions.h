#include <stdio.h>
#include <math.h>

float f_function(float x, float t) {
  return tan(t);
}

float alpha_function(float t) {
  return pow(t, 2) - log10(cos(t));
}

float phi_function(float x) {
  return pow(x, 2);
}

