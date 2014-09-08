#include <stdio.h>
#include <math.h>
#include "grid.h"

#define COEFFICIENT_A 1
#define ITERATION_COUNT 4
#define MAX_X_VALUE 1.0

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
  Grid grid[ITERATION_COUNT] = {
    {0.8, 10, 4, 5}
  };
  int i;

  for (i = 0; i < ITERATION_COUNT; i++) {
    grid_init(grid);
    set_grid_values(grid);
    printf("\n");
  }
  return 0;
}
