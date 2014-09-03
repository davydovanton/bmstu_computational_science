#include <stdio.h>
#include <math.h>

#define COEFFICIENT_A 1
#define KURANT_NUMBER 0.8
#define MAX_X_VALUE 1.0
#define STEPS_NUMBER_M 10
#define STEPS_NUMBER_N 4

static const int STEP_NUMBER_MP = 5;
static const float H_INDEX = MAX_X_VALUE / STEPS_NUMBER_M;
static const float TAU_INDEX = (H_INDEX * KURANT_NUMBER) / COEFFICIENT_A;

void setInitializeConditions(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]);
void setGridValues(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]);
void printMatrix(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]);

int main(void) {
  float grid[STEPS_NUMBER_N][STEPS_NUMBER_M] = {0};
  setInitializeConditions(grid);
  setGridValues(grid);

  printMatrix(grid);
  return 0;
}

float alphaFunction(float t) {
  return pow(t, 2) - log10(cos(t));
}

float phiFunction(float x) {
  return pow(x, 2);
}

void setInitializeConditions(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int j, n;

  for (j = 1; j < STEPS_NUMBER_M; j++) {
    grid[0][j] = phiFunction(j * H_INDEX);
  }

  for (n = 1; n < STEPS_NUMBER_N; n++) {
    grid[n][0] = alphaFunction(n * TAU_INDEX);
  }
}

float fFunction(float x, float t) {
  return tan(t);
}

float topGridValue(float centerY, float leftY, float tau, float fFunction) {
  return centerY + KURANT_NUMBER * (centerY - leftY) + tau * fFunction;
}

void setGridValues(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int j, n;

  for (n = 1; n < STEPS_NUMBER_N; n++) {
    for (j = 1; j < STEPS_NUMBER_M; j++) {
      grid[n][j] = topGridValue(grid[n][j], grid[n][j - 1], TAU_INDEX, fFunction(j * H_INDEX, n * TAU_INDEX));
    }
  }
}

void printMatrix(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int i, j;

  for (i = STEPS_NUMBER_N - 1; i >= 0; i--) {
    for (j = 0; j < STEPS_NUMBER_M; j++) {
      printf ("% 1.5f ", grid[i][j]);
    }
    printf ("\n");
  }
}
