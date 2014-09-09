#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

#define ITERATION_COUNT 5

struct Grid Grids[ITERATION_COUNT] = {
  { 101,  41, 10, 0.8, 0.0, 0.0 },
  { 201,  81, 20, 0.8, 0.0, 0.0 },
  { 401, 161, 40, 0.8, 0.0, 0.0 },
  { 101,  81, 10, 0.4, 0.0, 0.0 },
  { 101,  21, 10, 1.6, 0.0, 0.0 }
};

void print_matrix(struct Grid *grid) {
  int i, j;

  for (i = grid->steps_number_n - 1; i >= 0; i--) {
    for (j = 0; j < grid->steps_number_m; j++) {
      printf ("% 1.5f ", grid->grid[i][j]);
    }
    printf ("\n");
  }
  printf ("\n");
}

void print_node(struct Grid *grid, int iteration) {
  printf ("%1.5f\n", grid->grid[iteration][grid->steps_number_mp - 1]);
}

static void memory_allocation(struct Grid *grid) {
  grid->grid = (float **)malloc(sizeof(float *) * grid->steps_number_n);

  for(int i = 0; i < grid->steps_number_n; i++) {
    grid->grid[i] = (float *)malloc(sizeof(float) * grid->steps_number_m);
  }
}

static void memory_free(struct Grid *grid) {
  for(int i=0; i < grid->steps_number_n; i++) {
    free(grid->grid[i]);
  }
  free(grid->grid);
}

static void run_programm(struct Grid *grid, int iteration) {
  memory_allocation(grid);
  grid_init(grid);
  set_grid_values(grid);

  print_node(grid, iteration);
  memory_free(grid);
}

int main(void) {
  for(int i = 0; i < ITERATION_COUNT; i++) {
    run_programm(&Grids[i], i + 1);
  }

  return 0;
}
