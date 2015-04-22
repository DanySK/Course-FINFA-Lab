#include "functions.h"

int main(void){
  printf("Testing minThree with {1, 2, 3}: %d\n", minThree(1,2,3));
  printf("Testing minThree with {1, 2, -3}: %d\n", minThree(1,2,-3));
  printf("Testing randInInterval(50,60): %d\n", randInInterval(50,60));
  printf("Testing randInInterval(1000,1001): %d\n", randInInterval(1000, 1001));
  printf("Testing randInInterval(-500,500): %d\n", randInInterval(-500, 500));
  printf("Testing previousSquare(9): %d\n", previousSquare(9));
  printf("Testing previousSquare(90): %d\n", previousSquare(90));
  printf("Testing previousSquare(900): %d\n", previousSquare(900));
  printf("Testing previousSquare(9000): %d\n", previousSquare(9000));
  printf("Testing solveEquation(0,0,0): %f\n", solveEquation(0, 0, 0));
  printf("Testing solveEquation(1,1,1): %f\n", solveEquation(1, 1, 1));
  printf("Testing solveEquation(3.6,95.24,9.7): %f\n", solveEquation(3.6,95.24,9.7));
}
