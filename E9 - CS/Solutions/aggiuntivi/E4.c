#include <stdio.h>
#include <stdlib.h>

int **matr(int size,int elem){
    int **p=(int **)malloc(size*sizeof(int *));
    int i;
    for (i=0;i<size;i++){
        p[i]=(int *)malloc(size*sizeof(int));
        int j;
        for (j=0;j<size;j++) p[i][j]=elem;
    }
    return p;
}

void reset_diagonal(int **m,int size){
    int i;
    for (i=0;i<size;i++) m[i][i]=0;
}

int **matr_new(int size,int elem){
    int **p=(int **)malloc(size*sizeof(int *));
    int i;
    for (i=0;i<size;i++){
        p[i]=(int *)malloc(size*sizeof(int));
        int j;
        for (j=0;j<size;j++){
            if (i==j){
                p[i][j]=elem;
            }else{ 
                p[i][j]=0;
            }
        } 
    }
    return p;

}

int main(void){
    int **m=matr(3,10);
    reset_diagonal(m,3);
    printf("%d %d %d\n%d %d %d\n%d %d %d\n",m[0][0],m[0][1],m[0][2],m[1][0],m[1][1],m[1][2],m[2][0],m[2][1],m[2][2]);
    printf("---------------\n");
    int **n=matr_new(3,10);
    printf("%d %d %d\n%d %d %d\n%d %d %d\n",n[0][0],n[0][1],n[0][2],n[1][0],n[1][1],n[1][2],n[2][0],n[2][1],n[2][2]);
    return 0;
}
