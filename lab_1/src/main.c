#include <stdio.h>
#include <stdlib.h>
#include "portion.h"

#define ITERATION_COUNT 5

struct Portion Portions[ITERATION_COUNT] = {
  { 101,  41, 10, 0.8, 0.0, 0.0 },
  { 201,  81, 20, 0.8, 0.0, 0.0 },
  { 401, 161, 40, 0.8, 0.0, 0.0 },
  { 101,  81, 10, 0.4, 0.0, 0.0 },
  { 101,  21, 10, 1.6, 0.0, 0.0 }
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

void print_node(struct Portion *portion, int iteration) {
  printf ("%1.5f\n", portion->grid[iteration][portion->steps_number_mp - 1]);
}

static void memory_allocation(struct Portion *portion) {
  portion->grid = (float **)malloc(sizeof(float *) * portion->steps_number_n);

  for(int i = 0; i < portion->steps_number_n; i++) {
    portion->grid[i] = (float *)malloc(sizeof(float) * portion->steps_number_m);
  }
}

static void memory_free(struct Portion *portion) {
  for(int i=0; i < portion->steps_number_n; i++) {
    free(portion->grid[i]);
  }
  free(portion->grid);
}

static void run_programm(struct Portion *portion, int iteration) {
  memory_allocation(portion);
  portion_init(portion);
  set_portion_values(portion);

  print_node(portion, iteration);
  memory_free(portion);
}

int main(void) {
  for(int i = 0; i < ITERATION_COUNT; i++) {
    run_programm(&Portions[i], i + 1);
  }

  return 0;
}
