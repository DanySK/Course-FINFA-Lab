#include <stdio.h>
#include <stdlib.h>

int **matr(int size,int elem){
  int **p = (int **)malloc(size*sizeof(int *));
  int i;
  for (i=0;i<size;i++){
    p[i] = (int *)malloc(size*sizeof(int));
    int j;
    for (j=0;j<size;j++) {
      p[i][j]=elem;
    }
  }
  return p;
}

void matrixCreator(int size, int ***res) {
  *res = (int **)malloc(size*sizeof(int *));
  int i;
  for (i=0;i<size;i++){
    (*res)[i] = (int *)malloc(size*sizeof(int));
    int j;
    for (j=0;j<size;j++) {
      (*res)[i][j] = (i*size) + j;
    }
  }
}

void reset_diagonal(int **m,int size){
  int i;
  for (i=0;i<size;i++) {
    m[i][i]=0;
  }
}

void print_matrix(int **m, int hsize, int vsize) {
  int i, j;
  for(i = 0; i < vsize; i++){
    for(j = 0; j < hsize; j++) {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }
}

int main(void){
  const int size = 10;
  int **m;
  matrixCreator(size, &m);
  printf("Created matrix:\n");
  print_matrix(m, size, size);
  reset_diagonal(m,size);
  printf("Matrix after diagonal reset:\n");
  print_matrix(m, size, size);
  return 0;
}
