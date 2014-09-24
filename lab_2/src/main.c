#include <stdio.h>
#include <math.h>
#include "linear_equations.h"

#define LINEAR_SYSTEM_SIZE 4

static void print_result(double *alpha, double *beta, double *x) {
  int i;

  for(i = 0; i < LINEAR_SYSTEM_SIZE; i++) {
    printf("Alpha%i value: % 3.3f\t", i+1, alpha[i]);
    printf("Beta%i value: % 3.3f\t", i+1, beta[i]);
    printf("X%i value: % e\n", i+1, x[i]);
  }
}

int main(){
  double a[LINEAR_SYSTEM_SIZE] = {  0,  1,  4,  1 };
  double b[LINEAR_SYSTEM_SIZE] = {  2,  4,  7,  1 };
  double c[LINEAR_SYSTEM_SIZE] = {  1, -3,  2,  0 };
  double s[LINEAR_SYSTEM_SIZE] = {  2, -8, 29,  7 };

  double alpha[LINEAR_SYSTEM_SIZE] = { 0.0 };
  double beta[LINEAR_SYSTEM_SIZE] = { 0.0 };
  double x[LINEAR_SYSTEM_SIZE] = { 0.0 };

  alpha[0] = first_alpha_value_calculate(c[0], b[0]);
  beta[0] = first_beta_value_calculate(s[0], b[0]);

  alpha_values_calculate(alpha, a, b, c);
  beta_values_calculate(alpha, beta, a, b, s);

  x_values_calculate(alpha, beta, x);

  print_result(alpha, beta, x);
  return 0;
}
