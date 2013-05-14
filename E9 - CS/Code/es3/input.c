#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main(int argc, char **argv) {
  if(argc < 3) {
    printf("This program requires at least two parameters. Terminating.\n");
    return 1;
  }
  Point2D p;
  p.x = atof(argv[1]);
  p.y = atof(argv[2]);
  printf("Created a new Point2D: (%f, %f))\n", p.x, p.y);
  return 0;
}
