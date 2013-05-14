#include <stdio.h>
 
void increase(int *i){
  (*i)++;
}

void decrease(int *i){
  (*i)--;
}

void twice(int *i){
  (*i)*=2;
}

void applyfunction(int * array, void f(int *i), int start, int end) {
  int i;
  for(i = start; i < end; i++) {
    f(&array[i]);
  }
}

void printarray(int *a, int size) {
  int i;
  printf("[");
  for(i = 0; i < size-1; i++) {
    printf("%d, ", a[i]);
  }
  printf("%d]\n", a[size-1]);
}

int main(void) {
  int a[] = {0,1,2,3,4,5,6,7,8};
  printf("Array iniziale: ");
  printarray(a, 9);
  
  applyfunction(a, increase, 0, 3);
  applyfunction(a, decrease, 3, 6);
  applyfunction(a, twice, 6, 9);
  
  printf("Array finale: ");
  printarray(a, 9);
  
  return 0;
}