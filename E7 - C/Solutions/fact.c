#include <stdio.h>

#define MAX_VAL 20

unsigned long int fact(int n){
  if(n > MAX_VAL || n < 0){
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
    fact(20) == 2432902008176640000l &&
    fact(21) == 0l;
}

int main(){
  if(test()){
    printf("OK\n");
  } else {
    printf("Error\n");
  }
  return 0;
}

 
