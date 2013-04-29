#include "functions.h"

double x(double x) {
	return x;
}

double sinx(double x) {
	return sin(x);
}

double cosx(double x) {
	return cos(x);
}

double ex(double x) {
	return exp(x);
}

double logx(double x) {
	return log(x);
}

double tanx(double x) {
	return tan(x);
}

int minThree(int a, int b, int c) {
  if(a < b) {
    if(a < c) {
      return a;
    }
    if(b < c) {
      return b;
    }
    return c;
  }
  if(b < c) {
    return b;
  }
  return c;
}

int randInInterval(int a, int b) {
  return a + rand() % (b - a);
}

int previousSquare(int x) {
  int sq = (int) sqrt(x);
  return sq * sq;
}

double solveEquation(double a, double b, double c) {
  double delta = b * b - 4 * a * c;
  if(delta < 0 || (a == 0 && b == 0)){
    return NAN;
  }
  return (sqrt(delta) - b) / (2 * a); 
}
