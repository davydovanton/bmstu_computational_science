#include <stdio.h>
#include <math.h>

#define COEFFICIENT_A 1
#define ITERATION_COUNT 4
#define KURANT_NUMBER 0.8
#define MAX_X_VALUE 1.0
#define STEPS_NUMBER_M 10
#define STEPS_NUMBER_N 4

static const int STEP_NUMBER_MP = 5;
static const float H_INDEX = MAX_X_VALUE / STEPS_NUMBER_M;
static const float TAU_INDEX = (H_INDEX * KURANT_NUMBER) / COEFFICIENT_A;

void set_initialize_conditions(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]);
void set_grid_values(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]);
void print_matrix(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]);

void calculate_convection_equation() {
  float grid[STEPS_NUMBER_N][STEPS_NUMBER_M] = {0};
  set_initialize_conditions(grid);
  set_grid_values(grid);

  print_matrix(grid);
}

float alpha_function(float t) {
  return pow(t, 2) - log10(cos(t));
}

float phi_function(float x) {
  return pow(x, 2);
}

void set_initialize_conditions(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int j, n;

  for (j = 1; j < STEPS_NUMBER_M; j++) {
    grid[0][j] = phi_function(j * H_INDEX);
  }

  for (n = 1; n < STEPS_NUMBER_N; n++) {
    grid[n][0] = alpha_function(n * TAU_INDEX);
  }
}

float f_function(float x, float t) {
  return tan(t);
}

float top_grid_value(float centerY, float leftY, float tau, float f_function) {
  return centerY + KURANT_NUMBER * (centerY - leftY) + tau * f_function;
}

void set_grid_values(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int j, n;

  for (n = 1; n < STEPS_NUMBER_N; n++) {
    for (j = 1; j < STEPS_NUMBER_M; j++) {
      grid[n][j] = top_grid_value(grid[n][j], grid[n][j - 1], TAU_INDEX, f_function(j * H_INDEX, n * TAU_INDEX));
    }
  }
}

void print_matrix(float grid[STEPS_NUMBER_N][STEPS_NUMBER_M]) {
  int i, j;

  for (i = STEPS_NUMBER_N - 1; i >= 0; i--) {
    for (j = 0; j < STEPS_NUMBER_M; j++) {
      printf ("% 1.5f ", grid[i][j]);
    }
    printf ("\n");
  }
}

int main(void) {
  int i;

  for (i = 1; i <= ITERATION_COUNT; i++) {
    calculate_convection_equation();
    printf("\n");
  }
  return 0;
}
