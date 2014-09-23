#include <stdio.h>
#include <stdlib.h>
#include "portion.h"

#define ITERATION_COUNT 5

struct Portion Portions[ITERATION_COUNT] = {
  { 101,  41, 10, 0.8,   0.01, 0.0 },
  { 201,  81, 20, 0.8,  0.005, 0.0 },
  { 401, 161, 40, 0.8, 0.0025, 0.0 },
  { 101,  81, 10, 0.4,   0.01, 0.0 },
  { 101,  21, 10, 1.6,   0.01, 0.0 }
};

void print_matrix(struct Portion *portion) {
  int i, j;

  for (i = portion->steps_number_n - 1; i >= 0; i--) {
    for (j = 0; j < portion->steps_number_m; j++) {
      printf ("% 1.5f ", portion->grid[i][j]);
    }
    printf ("\n");
  }
  printf ("\n");
}

void print_node(struct Portion *portion) {
  int j;

  for (j = 0; j < portion->steps_number_m; j = j + portion->steps_number_mp) {
    printf ("X value: %  d; U(x, t) value: % 1.5f; U(x, t) analytic value: % 1.5f",
        j,
        portion->grid[portion->steps_number_n - 1][j],
        analytic_function(j, portion->steps_number_n - 1));
    printf ("\n");
  }
  printf ("\n\n\n");
}

static void memory_allocation(struct Portion *portion) {
  int i;

  portion->grid = (double **)malloc(sizeof(double *) * portion->steps_number_n);

  for(i = 0; i < portion->steps_number_n; i++) {
    portion->grid[i] = (double *)malloc(sizeof(double) * portion->steps_number_m);
  }
}

static void memory_free(struct Portion *portion) {
  int i;

  for(i=0; i < portion->steps_number_n; i++) {
    free(portion->grid[i]);
  }
  free(portion->grid);
}

static void run_programm(struct Portion *portion) {
  memory_allocation(portion);
  portion_init(portion);
  set_portion_values(portion);

  print_node(portion);
  memory_free(portion);
}

int main(void) {
  int i;

  for(i = 0; i < ITERATION_COUNT; i++) {
    run_programm(&Portions[i]);
  }
  return 0;
}
