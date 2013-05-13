#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 500

void array_creator (int size, int **res) {
  (*res) = (int *) malloc(size * sizeof(int));
  int *a = (*res);
  int i;
  for (i = 0; i < size; i++) {
    a[i] = i;
  }
}

int main (void) {
  int *array;
  /*
   * Passo il puntatore all'array (ossia un puntatore a puntatore)
   */
  array_creator(ARRAY_SIZE, &array);
  int i;
  for (i = 0; i < ARRAY_SIZE; i++) {
     printf("%d ", array[i]);
  }
  printf("\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    if (array[i] != i) {
      printf("Error at %d\n", i);
      return 1;
    }
  }
  printf("All done, everything looks fine.\n");
  return 0;
}


