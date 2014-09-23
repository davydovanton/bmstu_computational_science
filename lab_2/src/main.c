#include <stdio.h>
#include <math.h>
#include "linear_equations.h"

#define LINEAR_SYSTEM_SIZE 4

int main(){
  int i;
  double a[LINEAR_SYSTEM_SIZE] = {  0, -1,  2, 1 };
  double b[LINEAR_SYSTEM_SIZE] = {  2,  7,  6, 1 };
  double c[LINEAR_SYSTEM_SIZE] = { -1,  4, -1, 0 };
  double d[LINEAR_SYSTEM_SIZE] = {  1,  0, -4, 2 };
  /* double a[3] = { 0,  1,  2 }; */
  /* double b[3] = { 2,  7,  5 }; */
  /* double c[3] = { 1, -2,  0 }; */
  /* double d[3] = { 4,  9, 19 }; */

  double alpha[LINEAR_SYSTEM_SIZE];
  double beta[LINEAR_SYSTEM_SIZE];
  double x[LINEAR_SYSTEM_SIZE];

  alpha[0] = first_alpha_value_calculate(c[0], b[0]);
  alpha_values_calculate(alpha, a, c, b);

  beta[0] = first_beta_value_calculate(d[0], b[0]);
  beta_values_calculate(alpha, beta, a, b, d);

  x_values_calculate(alpha, beta, x);

  for(i = 0; i < LINEAR_SYSTEM_SIZE; i++) {
    printf("X%i value: %3.1f\n", i, x[i]);
  }
  return 0;
}
