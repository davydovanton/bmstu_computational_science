#include <stdio.h>
#include <math.h>
#include "math_functions.h"

#define COEFFICIENT_A 1

struct Portion {
  int steps_number_m;
  int steps_number_n;
  int steps_number_mp;
  double kurant_number;
  double h_index;
  double tau_index;
  double **grid;
};

static double top_portion_value(struct Portion *portion, int n, int j) {
  double center_y = portion->grid[n][j];
  double kurant_number = portion->kurant_number;
  double left_y = portion->grid[n][j - 1];
  double tau = portion->tau_index;
  double f_function_data = f_function(n * portion->tau_index);

  return center_y - kurant_number * (center_y - left_y) + tau * f_function_data;
}

static void set_portion_values(struct Portion *portion) {
  int i, j;

  for (i = 1; i < portion->steps_number_n; i++) {
    for (j = 1; j < portion->steps_number_m; j++) {
      portion->grid[i][j] = top_portion_value(portion, i - 1, j);
    }
  }
}

static void portion_init(struct Portion *portion) {
  int i, j;

  portion->tau_index = ((portion->h_index * portion->kurant_number) / COEFFICIENT_A);

  for (i = 0; i < portion->steps_number_m; i++) {
    portion->grid[0][i] = phi_function(i * portion->h_index);
  }

  for (j = 0; j < portion->steps_number_n; j++) {
    portion->grid[j][0] = alpha_function(j * portion->tau_index);
  }
}
