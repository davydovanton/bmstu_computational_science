#include <stdio.h>
#include <stdlib.h>

int main(void) {
  for(int i=0; i < 1000000000; i++) {
    float **grid = (float **)malloc(sizeof(float *)*4);
    for(int i=0; i < 4; i++) {
      grid[i] = (float *)malloc(sizeof(float)*10);
    }

    for(int i=0; i < 4; i++) {
      free(grid[i]);
    }
    free(grid);
  }
  return 0;
}
