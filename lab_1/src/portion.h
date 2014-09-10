#include <stdio.h>
#include <math.h>
#include "math_functions.h"

#define COEFFICIENT_A 1
#define MAX_X_VALUE 1.0

struct Portion {
  int steps_number_m;
  int steps_number_n;
  int steps_number_mp;
  float kurant_number;
  float h_index;
  float tau_index;
  float **grid;
};

static float top_portion_value(struct Portion *portion, int n, int j) {
  float center_y = portion->grid[n][j];
  float kurant_number = portion->kurant_number;
  float left_y = portion->grid[n][j - 1];
  float tau = portion->tau_index;
  float f_function_data = f_function(n * portion->tau_index);

  return center_y - kurant_number * (center_y - left_y) + tau * f_function_data;
}

static void set_portion_values(struct Portion *portion) {
  for (int i = 1; i < portion->steps_number_n; i++) {
    for (int j = 1; j < portion->steps_number_m; j++) {
      portion->grid[i][j] = top_portion_value(portion, i - 1, j);
    }
  }
}

static void portion_init(struct Portion *portion) {
  portion->h_index = MAX_X_VALUE / portion->steps_number_m;
  portion->tau_index = ((portion->h_index * portion->kurant_number) / COEFFICIENT_A);

  for (int i = 0; i < portion->steps_number_m; i++) {
    portion->grid[0][i] = phi_function(i * portion->h_index);
  }

  for (int j = 0; j < portion->steps_number_n; j++) {
    portion->grid[j][0] = alpha_function(j * portion->tau_index);
  }
}
