#include <stdio.h>
#include "grid.h"

#define ITERATION_COUNT 1

void print_matrix(struct Grid grid) {
  int i, j;

  for (i = grid.steps_number_n - 1; i >= 0; i--) {
    for (j = 0; j < grid.steps_number_m; j++) {
      printf ("% 1.5f ", grid.grid[i][j]);
    }
    printf ("\n");
  }
}

int main(void) {
  struct Grid grid = { 10, 4, 5, 0.8, 0.0, 0.0, 0 };
  int i;

  printf(&grid.steps_number_m);
  printf("\n");
  

  /* for (i = 0; i < ITERATION_COUNT; i++) { */
  /*   #<{(| grid_init(&grid); |)}># */
  /*   print_matrix(grid); */
  /*   printf("\n"); */
  /* } */
  return 0;
}
