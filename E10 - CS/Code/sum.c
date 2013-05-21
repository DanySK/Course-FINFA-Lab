#include <stdio.h>

int sum(int *a, int size) {
  int tmp = 0;
  for(; size >= 0; size--) {
    tmp += a[size - 1];
  }
  return tmp;
}

int main(int argc, char **argv) {
  int a[] = {0, 1, 2, 3, 4, 5};
  printf("Sum is %d\n", sum(a, 6));
  return 0;
}
