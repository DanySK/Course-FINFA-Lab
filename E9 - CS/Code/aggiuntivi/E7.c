#include <stdio.h>
#include <stdlib.h>

/*  Realizzare la funziona somma sotto riportata che esegue
    l'addizione delle due matrici quadrate fornite in ingresso,
    riportando il uscita come una nuova matrice.
    Come riferimento si consideri che l'esecuzione del test deve
    fornire risultato positivo.
    */

int **somma(int size,int **m1,int **m2){
    return NULL;
}

int test(void){
    int a1[]={10,20,30};
    int a2[]={0,0,0};
    int a3[]={1,2,3};
    int *m1[]={a1,a2,a3};
    int *m2[]={a3,a2,a1};
    int **res=somma(3,m1,m2);
    return  res[0][0]==11 && res[0][1]==22 && res[0][2]==33 &&
            res[1][0]==0 && res[1][1]==0 && res[1][2]==0 &&
            res[2][0]==11 && res[2][1]==22 && res[2][2]==33 &&
            a1[0]==10 && a1[1]==20 && a1[2]==30 &&
            a2[0]==0 && a2[1]==0 && a2[2]==0 &&
            a3[0]==1 && a3[1]==2 && a3[2]==3;
}

int main(void){
    printf("%d\n",test());
    return 0;
}
