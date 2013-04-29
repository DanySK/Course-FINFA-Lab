 
#include <stdio.h>

void printEmptyMatrix(const int n, const int v1, const int v2) {
  const int nxn = n * n;
  int i = 0;
  for(; i < nxn; i++){
    if(i > 0 && i % n == 0) {
      printf("\n");
    }
    printf("%d ", i % 2 == 0? v1 : v2);
  }
  printf("\n");
}

int main(){
  printEmptyMatrix(30, 4, 6);
  return 0;
}