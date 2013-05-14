#include <stdio.h>
#include <stdlib.h>

/*

- Questo file contiene un funzione per creare matrici, una funzione per modificare matrici, e un main di prova: analizzare il comportamento di queste funzioni.
- Compilare il sorgente utilizzando il comando gcc E4.c -o e4 ed eseguire verificando che il comportamento sia conforme rispetto alla precedente analisi.
- Modificare la funzione int **matr(int, int) in modo che restituisca una matrice con tutti gli elementi a 0 eccetto quelli sulla diagonale, che saranno impostati al valore elem
- Modificare il main, in modo da collaudare la nuova funzione creata, compilare E4.c e lanciare in esecuzione l'eseguibile creato, accertandosi del corretto funzionamento della funzione appena realizzata


*/

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

int main(void){
    int **m=matr(3,10);
    reset_diagonal(m,3);
    printf("%d %d %d\n%d %d %d\n%d %d %d\n",m[0][0],m[0][1],m[0][2],m[1][0],m[1][1],m[1][2],m[2][0],m[2][1],m[2][2]);
    return 0;
}
