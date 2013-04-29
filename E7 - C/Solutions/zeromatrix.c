 
#include <stdio.h>

void printEmptyMatrix(int n) {
  const int nxn = n * n;
  int i = 0;
  for(; i < nxn; i++){
    if(i > 0 && i % n == 0) {
      printf("\n");
    }
    printf("0 ");
  }
  printf("\n");
}

int main(){
  printEmptyMatrix(30);
  return 0;
}