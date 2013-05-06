#include <stdio.h>
#define MAX_VALUE (sizeof(unsigned long) == 4 ? 12 : 20)

/*
 * Soluzione modificata dietro suggerimento di Federico Pari
 */
unsigned long int fact(int n){
  if(n > MAX_VALUE || n < 0){
      return 0;
  }
  unsigned long int res = 1;
  int i = 2;
  for(; i<=n; i++){
    res *= i;
  }
  return res;
}

int test(void) {
  return fact(1) == 1l &&
    fact(0) == 1l &&
    fact(10) == 3628800l &&
    fact(-10) == 0l &&
    fact(12) == 479001600l &&
    fact(13) == (MAX_VALUE == 12 ? 0l : 6227020800l) &&
    fact(20) == (MAX_VALUE == 12 ? 0l : 2432902008176640000l);
}

int main(){
  printf("This executable has been compiled with a %lubit compiler, and MAX_VALUE is consequently %d\n", sizeof(unsigned long)*8, MAX_VALUE);
  if(test()){
    printf("OK\n");
  } else {
    printf("Error\n");
  }
  return 0;
}
