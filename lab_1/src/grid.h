typedef struct {
  float kurant_number;
  int steps_number_m;
  int steps_number_n;
  int steps_number_mp;
  float h_index;
  float tau_index;
  float **grid;
} Grid;

float f_function(float x, float t) {
  return tan(t);
}

float alpha_function(float t) {
  return pow(t, 2) - log10(cos(t));
}

float phi_function(float x) {
  return pow(x, 2);
}

float top_grid_value(float centerY, float leftY, float tau, float f_function) {
  return centerY + KURANT_NUMBER * (centerY - leftY) + tau * f_function;
}

void grid_init(Grid *grid) {
  int j, n;

  grid->h_index = MAX_X_VALUE / grid->steps_number_m;
  grid->tau_index = ((grid->h_index * grid->kurant_number) / COEFFICIENT_A);

  for (j = 0; j < grid->steps_number_m; j++) {
    grid->grid[0][j] = phi_function(j * grid->h_index);
  }

  for (n = 0; n < grid->steps_number_n; n++) {
    grid->grid[n][0] = alpha_function(n * grid->tau_index);
  }
}

void set_grid_values(Grid *grid) {
  int j, n;

  for (n = 0; n < grid->steps_number_m; n++) {
    for (j = 0; j < grid->steps_number_n; j++) {
      // grid->grid[n][j] = top_grid_value(grid[n][j], grid[n][j - 1], TAU_INDEX, f_function(j * H_INDEX, n * TAU_INDEX));
    }
  }
}

