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

// float top_grid_value(struct Grid *grid, int j, int n) {
//   float center_y = grid->grid[n][j];
//   float kurant_number = grid->kurant_number;
//   float left_y = grid->grid[n][j - 1];
//   float tau = grid->tau_index;
//   float f_function_data = f_function(j * grid->h_index, n * grid->tau_index);
//
//   return center_y + kurant_number * (center_y - left_y) + tau * f_function_data;
// }
//
// void set_grid_values(struct Grid *grid) {
//   int j, n;
//
//   for (n = 0; n < grid->steps_number_m; n++) {
//     for (j = 0; j < grid->steps_number_n; j++) {
//       grid->grid[n][j] = top_grid_value(&grid, j, n);
//     }
//   }
// }

static void grid_init(struct Grid *grid) {
  int j, n;

  grid->h_index = MAX_X_VALUE / grid->steps_number_m;
  grid->tau_index = ((grid->h_index * grid->kurant_number) / COEFFICIENT_A);

  for (j = 0; j < grid->steps_number_m; j++) {
    grid->grid[0][j] = phi_function(j * grid->h_index);
  }

  for (n = 0; n < grid->steps_number_n; n++) {
    grid->grid[n][0] = alpha_function(n * grid->tau_index);
  }

  // set_grid_values(&grid);
}
