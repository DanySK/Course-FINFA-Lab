 
#include <stdio.h>

void printEmptyMatrix(const int n, const int v) {
  const int nxn = n * n;
  int i = 0;
  for(; i < nxn; i++){
    if(i > 0 && i % n == 0) {
      printf("\n");
    }
    printf("%d ", v);
  }
  printf("\n");
}

int main(){
  printEmptyMatrix(30, 4);
  return 0;
}