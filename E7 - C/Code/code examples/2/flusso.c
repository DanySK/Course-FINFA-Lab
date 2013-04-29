// flusso.c
#include <stdio.h>

int f(int a){
  printf("%d\n",a);
  int z;
  printf("%d\n",z); // quanto vale z?
  return 112;
  z=z+1;
}

int g(int x){
    // niente return!!
}

int main(){
    f(1.99);
    printf("main: %d\n",g(10));
    // nota che qui manca il return!!
}
