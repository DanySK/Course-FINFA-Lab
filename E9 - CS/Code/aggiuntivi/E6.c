#include <stdio.h>
#include <stdlib.h>

/*
- Questo file contiene un main di prova che effettua la creazione di array di complessi secondo diverse modalità: analizzare e comprendere il comportamento delle funzioni definite
- Compilare il sorgente utilizzando il comando gcc E6.c -o e6 ed eseguire così da verificare che il
comportamento sia conforme a quanto atteso
 */

struct complex {
    double re;
    double im;
};

typedef struct complex Complex;

int main(void){
    int i;
    // Caso 1: 1000 complessi in un array sullo stack
    Complex c1[1000];
    for (i=0;i<1000;i++){
        c1[i].re=i;
        c1[i].im=i;
        // o anche: c[i].re=c[i].im=i;
    }
    // nota, non c'è nulla da deallocare

    // Caso 2: 1000 complessi in un array sullo heap
    Complex *c2=(Complex *)malloc(1000*sizeof(Complex));
    for (i=0;i<1000;i++){
        c2[i].re=i;
        c2[i].im=i;
    }
    // si dealloca l'array sullo heap
    free(c2);
    // Caso 3: un array (nello stack) di 1000 puntatori a complessi sullo heap
    Complex *c3[1000]; // sarebbe un array di 1000 puntatori
    for (i=0;i<1000;i++){
        c3[i]=(Complex *)malloc(sizeof(Complex));
        c3[i]->re=i;
        c3[i]->im=i;
    }
    // si deallocano i c3[i]
    for (i=0;i<1000;i++){
        free(c3[i]);
    }
    // Caso 4: un array (nello heap) di 1000 puntatori a complessi sullo heap
    Complex **c4=(Complex **)malloc(1000*sizeof(Complex *));
    for (i=0;i<1000;i++){
        c4[i]=(Complex *)malloc(sizeof(Complex));
        c4[i]->re=i;
        c4[i]->im=i;
    }
    // si deallocano i c4[i], poi c4
    for (i=0;i<1000;i++){
        free(c4[i]);
    }
    free(c4);
    return 0;
}
