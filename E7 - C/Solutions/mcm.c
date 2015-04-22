#include <stdio.h>

int mcm(int a, int b){
  if(a > 0 && b > 0){
    int a1 = a;
    int b1 = b;
    for(; a1 != b1; ){
      if(a1 < b1) {
	a1 += a;
      } else {
	b1 += b;
      }
    }
    return a1;
  }
  return -1;
}

int test(void) {
  return mcm(1,1) == 1 &&
    mcm(100,100) == 100 &&
    mcm(100,3) == 300 &&
    mcm(5,6) == 30 &&
    mcm(66,21) == 462;
}

int main(void){
  if(test()){
    printf("OK\n");
  } else {
    printf("Error\n");
  }
  return 0;
}

 
