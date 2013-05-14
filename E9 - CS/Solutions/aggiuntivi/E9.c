#include <stdio.h>
#include <stdlib.h>

/*  Costruire la funzione appendi sotto riportata che dati in
    ingresso due array, e un puntatore ad un intero,
    ha l'effetto di collegare quest'ultimo alla somma delle
    dimensioni dei due array, e di fornire in uscita un nuovo array
    ottenuto appendendo i due in ingresso.
    Come riferimento si consideri che l'esecuzione del test deve
    fornire risultato positivo.
    */

int *appendi(int *a1,int dim1,int *a2,int dim2,int *dim3){
    *dim3 = dim1+dim2;
    int *a3 = (int *)malloc(sizeof(int)*(*dim3));
    int i;
    for(i=0; i<dim1; i++){
        a3[i]=a1[i];
    }
    for(;i<*dim3;i++){
        a3[i]=a2[i-dim1];
    }
    return a3;
}


int test(void){
    int a1[]={10,20,30,40};
    int a2[]={1,2,3};
    int dim;
    int *res=appendi(a1,4,a2,3,&dim);
    return  dim==7 &&
            res[0]==10 &&
            res[1]==20 &&
            res[2]==30 &&
            res[3]==40 &&
            res[4]==1 &&
            res[5]==2 &&
            res[6]==3;              
}

int main(void){
    printf("%d\n",test());
    return 0;
}
