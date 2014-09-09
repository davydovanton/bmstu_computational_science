#include <stdio.h>
#include <math.h>
#include "math_functions.h"

#define COEFFICIENT_A 1
#define MAX_X_VALUE 1.0

// http://habrahabr.ru/post/142662/
struct Grid {
  int steps_number_m;
  int steps_number_n;
  int steps_number_mp;
  float kurant_number;
  float h_index;
  float tau_index;
  float **grid;
};

static float top_grid_value(struct Grid *grid, int j, int n) {
  float center_y = grid->grid[n][j];
  float kurant_number = grid->kurant_number;
  float left_y = grid->grid[n][j - 1];
  float tau = grid->tau_index;
  float f_function_data = f_function(j * grid->h_index, n * grid->tau_index);

  return center_y + kurant_number * (center_y - left_y) + tau * f_function_data;
}

static void set_grid_values(struct Grid *grid) {
  for (int i = 1; i < grid->steps_number_n; i++) {
    for (int j = 1; j < grid->steps_number_m; j++) {
      grid->grid[i][j] = top_grid_value(grid, j, i);
    }
  }
}

static void grid_init(struct Grid *grid) {
  grid->h_index = MAX_X_VALUE / grid->steps_number_m;
  grid->tau_index = ((grid->h_index * grid->kurant_number) / COEFFICIENT_A);

  for (int i = 0; i < grid->steps_number_m; i++) {
    grid->grid[0][i] = phi_function(i * grid->h_index);
  }

  for (int j = 0; j < grid->steps_number_n; j++) {
    grid->grid[j][0] = alpha_function(j * grid->tau_index);
  }
}
