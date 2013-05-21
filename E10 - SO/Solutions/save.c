#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INTERVAL 0.01
#define FILENAME "data.log"

int save(double *buffer, int samples) {
  FILE *f = fopen(FILENAME, "w");
  if(f == NULL) {
    return -1;
  }
  int i;
  for(i = 0; i < 2* samples; i+=2) {
    fprintf(f, "%f %f\n", buffer[i], buffer[i+1]);
  }
  fclose(f);
  return 0;
}

int main(int argc, char **argv){
  if(argc != 3) {
    printf("This program works with two numeric parameters.\n");
    return 1;
  }
  double start = atof(argv[1]);
  double end = atof(argv[2]);
  int samples = (end - start) / INTERVAL;
  double *buffer = (double *) malloc(2 * samples * sizeof(double));
  int i;
  for(i = 0; i < 2*samples;) {
    double cur = i/2 * INTERVAL + start;
    buffer[i++] = cur;
    buffer[i++] = cos(cur);
  }
  save(buffer, samples);
  free(buffer);
  return 0;
}

