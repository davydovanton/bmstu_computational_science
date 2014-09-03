#include <stdio.h>
#include <math.h>

#define COEFFICIENT_A 1
#define STEPS_NUMBER_M 10
#define STEPS_NUMBER_N 4

static const int STEP_NUMBER_MP = 5;
static const float KURANT_NUMBER = 0.8;

void setInitializeConditions(float dArea[STEPS_NUMBER_N][STEPS_NUMBER_M]);
void setGridValues(float dArea[STEPS_NUMBER_N][STEPS_NUMBER_M]);
void printMatrix(float dArea[STEPS_NUMBER_N][STEPS_NUMBER_M]);

int main(void) {
  float dArea [STEPS_NUMBER_N] [STEPS_NUMBER_M] = {0};
  setInitializeConditions(dArea);
  setGridValues(dArea);

  printMatrix(dArea);
  printf("\nEND\n");
  return 0;
}

float alphaFunction(float t) {
  return pow(t, 2) - log10(cos(t));
}

float phiFunction(float x) {
  return pow(x, 2);
}

void setInitializeConditions(float dArea[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int j, n;
  float h = 1.0 / STEPS_NUMBER_M;
  float tau = (h * KURANT_NUMBER) / COEFFICIENT_A;

  for (j=1; j < STEPS_NUMBER_M; j++) {
    dArea[0][j] = phiFunction(j * h);
  }

  for (n=1; n < STEPS_NUMBER_N; n++) {
    dArea[n][0] = alphaFunction(n * tau);
  }
}

float fFunction(float x, float t) {
  return tan(t);
}

float topGridValue(float centerY, float leftY, float tau, float fFunction) {
  return centerY + KURANT_NUMBER * (centerY - leftY) + tau * fFunction;
}

void setGridValues(float dArea[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int j, n;
  float h = 1.0 / STEPS_NUMBER_M;
  float tau = (h * KURANT_NUMBER) / COEFFICIENT_A;

  for (n=1; n < STEPS_NUMBER_N; n++) {
    for (j=1; j < STEPS_NUMBER_M; j++) {
      dArea[n][j] = topGridValue(dArea[n][j], dArea[n][j-1], tau, fFunction(j * h, n * tau));
    }
  }
}

void printMatrix(float dArea[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int i, j;

  for (i = 0; i < STEPS_NUMBER_N; i++) {
    for (j = 0; j < STEPS_NUMBER_M; j++) {
      printf ("%f  ", dArea[i][j]);
    }

    printf ("\n");
  }
}
