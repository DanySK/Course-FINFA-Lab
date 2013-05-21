#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FILENAME "data.log"

int load(double **buffer) {
  FILE *f = fopen(FILENAME, "r");
  if(f == NULL) {
    return -1;
  }
  /*
   * Compute number of samples
   */
  int samples = 0;
  double a;
  while(fscanf(f, "%lf %lf\n", &a, &a) == 2) {
    samples++;
  }
  rewind(f);
  *buffer = (double *) malloc(samples * 2 * sizeof(double));
  int i;
  for(i = 0; fscanf(f, "%lf %lf\n", &(*buffer)[i], &(*buffer)[i+1]) == 2; i+=2);
  fclose(f);
  return samples;
}

int main(int argc, char **argv){
  double **buffer = (double **) malloc(sizeof(double **));
  int samples = load(buffer);
  int i;
  for(i = 0; i < 2*samples; i+=2) {
    printf("%lf %lf\n", buffer[0][i], buffer[0][i+1]);
  }
  free(*buffer);
  return 0;
}

