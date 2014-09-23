#include <stdio.h>
#include <math.h>

#define LINEAR_SYSTEM_SIZE 4

static double first_alpha_value_calculate(double c, double b) {
  return -(c / b);
}

static double first_beta_value_calculate(double d, double b) {
  return (d / b);
}

double alpha_value_calculate(double c, double b, double prev_alpha, double a) {
  return - (c / (b + (prev_alpha * a)));
}

static void alpha_values_calculate(double *alpha, double *a, double *b, double *c) {
  int i;

  for (i = 1; i < LINEAR_SYSTEM_SIZE - 1; i++) {
    alpha[i] = alpha_value_calculate(c[i], b[i], alpha[i-1], a[i-1]);
  }
}

double beta_value_calculate(double alpha, double beta, double a, double b, double d) {
  return ((d - beta * a) / (b + alpha * a));
}

static void beta_values_calculate(double *alpha, double *beta, double *a, double *b, double *d) {
  int i;

  for (i = 1; i < LINEAR_SYSTEM_SIZE; i++) {
    beta[i]= beta_value_calculate(alpha[i-1], beta[i-1], a[i-1], b[i], d[i]);
  }
}

double x_value_calculate(double alpha, double beta, double x) {
  return ((alpha * x) + beta);
}

static void x_values_calculate(double *alpha, double *beta, double *x) {
  int i;

  x[2] = beta[2];
  for (i = LINEAR_SYSTEM_SIZE - 1; i > 0; i--) {
    x[i - 1] = x_value_calculate(alpha[i-1], x[i], beta[i-1]);
  }
}
