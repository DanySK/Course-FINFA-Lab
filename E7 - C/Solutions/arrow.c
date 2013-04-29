#include <stdio.h> 

void printCharLine(char c, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%c", c);
  }
}

void printArrow(int n){
  printCharLine(' ', n);
  printf("0\n");
  printCharLine('0', n+2);
  printf("\n");
  printCharLine('0', n+3);
  printf("\n");
  printCharLine('0', n+2);
  printf("\n");
  printCharLine(' ', n);
  printf("0\n");
}

int main(){
  printArrow(8);
}

 