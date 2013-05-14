#include <stdio.h>
#include <stdlib.h>

/*
- Questo file contiene tutte le funzioni necessarie per generare diversi tipi di sequenze, testate tramite un main di prova: analizzare e comprendere il funzionamento di tali funzioni.

- Compilare il sorgente utilizzando il comando gcc E5.c -o e5 ed eseguire verificando che il comportamento sia conforme rispetto alla precedente analisi

- Aggiungere una funzione int two2(int *p,int *start) simile alla funzione two ma che, avvalendosi della funzione create_seq (MA SENZA MODIFICARLA) crei una sequenza del tipo 1,2,2,3,3,4,4,...

- Modificare il main, aggiungendo prove di funzionamento sulla funzione creata, compilare E5.c e
lanciare in esecuzione l'eseguibile creato

 */

//stampa su console la sequenza di interi contenuti nell'array p[]
void printseq(int size,int p[]){
    int i;
    for (i=0;i<size;i++) {
        printf("%d ",p[i]);
    }
    printf("\n");
}

//funzione che crea una sequenza tramite la funzione f
int *createseq(int size,int first,int (*f)(int *,int *)){
    int *a=(int *)malloc(size*sizeof(int));
    a[0]=first;
    int i;
    for (i=1;i<size;i++) {
        a[i]=f(&a[i],a);
    }
    return a;
}

int constant(int *p,int *start){
    return p[-1];
}

int raise(int *p,int *start){
    return p[-1]+1;
}

int two(int *p,int *start){
    if (p-1==start) {
        return p[-1];
    }
    if (p[-1]==p[-2]) {
        return p[-1]+1;
    }
    return p[-1];
}

int fib(int *p,int *start){
    if (p-1==start) {
      return 1;
    }
    return p[-1]+p[-2];    
}


int main(void){
    int *p1=createseq(10,1,constant);
    int *p2=createseq(10,1,raise);
    int *p3=createseq(10,1,two);
    int *p4=createseq(10,1,fib);
    printseq(10, p1);
    printseq(10, p2);
    printseq(10, p3);
    printseq(10, p4);
    return 0;
}
