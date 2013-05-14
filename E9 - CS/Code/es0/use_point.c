#include "point.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  /*
   * Stack
   */
  Point2D p1;
  p1.x = 15.3;
  p1.y = 28.4;
  
  /*
   * Heap
   */
  Point2D *p2 = (Point2D *) malloc(sizeof(Point2D));
  p2 -> x = 3.7; // Equivalent to (*p2).x
  p2 -> y = 92.3;
  
  printf("I can see a point in your stack: [%f, %f]\n", p1.x, p1.y);
  printf("And I can see another in your heap: [%f, %f]\n", p2 -> x, p2 -> y);
  
  return 0;
}
