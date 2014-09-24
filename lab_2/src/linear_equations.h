#include <stdio.h>
#include <math.h>

#define LINEAR_SYSTEM_SIZE 4

static double first_alpha_value_calculate(double c, double b) {
  return (- (c / b));
}

static double first_beta_value_calculate(double s, double b) {
  return (s / b);
}

double alpha_value_calculate(double prev_alpha, double a, double b, double c) {
  return (- (c / (b + (prev_alpha * a))));
}

static void alpha_values_calculate(double *alpha, double *a, double *b, double *c) {
  int i;

  for (i = 1; i < LINEAR_SYSTEM_SIZE - 1; i++) {
    alpha[i] = alpha_value_calculate(alpha[i - 1], a[i], b[i], c[i]);
  }
}

double beta_value_calculate(double alpha, double beta, double a, double b, double s) {
  return ((s - beta * a) / (b + alpha * a));
}

static void beta_values_calculate(double *alpha, double *beta, double *a, double *b, double *s) {
  int i;

  for (i = 1; i < LINEAR_SYSTEM_SIZE; i++) {
    beta[i]= beta_value_calculate(alpha[i - 1], beta[i - 1], a[i], b[i], s[i]);
  }
}

double x_value_calculate(double alpha, double beta, double x) {
  return (alpha * x + beta);
}

static void x_values_calculate(double *alpha, double *beta, double *x) {
  int i;

  x[LINEAR_SYSTEM_SIZE - 1] = beta[LINEAR_SYSTEM_SIZE - 1];
  for (i = LINEAR_SYSTEM_SIZE - 2; i >= 0; i--) {
    x[i] = alpha[i] * x[i+1] + beta[i];
  }
}
