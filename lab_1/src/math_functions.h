#include <stdio.h>
#include <math.h>

float f_function(float t) {
  return tan(t);
}

float alpha_function(float t) {
  return pow(t, 2) - log(cos(t));
}

float phi_function(float x) {
  return pow(x, 2);
}

float analytic_function(int x, double t) {
  return (pow((x - t), 2) - log(cos(t)));
}
