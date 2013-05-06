#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 500

int *create_array (int size) {
  int *res = (int *) malloc(size * sizeof(int));
  int i;
  for (i = 0; i < size; i++) {
    res[i] = 0;
  }
  return res;
}

int main (void) {
  int *array = create_array(ARRAY_SIZE);
  int i;
  for (i = 0; i < ARRAY_SIZE; i++) {
    if (array[i] != 0) {
      printf("Error at %d\n", i);
      return 1;
    }
  }
  printf("All done, everything looks fine.\n");
  return 0;
}


