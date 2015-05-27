#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct triple {
    int *a;
    int *b;
    int *c;
} Triple;

void printTriple(Triple *t) {
    printf("(%d@%p, %d@%p, %d@%p)", *(t -> a), t -> a, *(t -> b), t -> b, *(t -> c), t -> c);
}

/* 
 * Realizzare la funzione f qui sotto indicata, prende in ingresso array di interi a, la sua dimensione.
 * Se la dimensione dell'array in ingresso è non è un multiplo di tre, viene restituito NULL.
 * Altrimenti, deve essere restituito un nuovo array di Triple, che dovrà essere accessibile al
 * chiamante, dove ciascuna Triple tiene i puntatori a tre elementi successivi di a.
 * 
 * Come riferimento si consideri che l'esecuzione del test deve fornire risultato positivo.
 */

Triple *f(int* a, int size)
{
    if (size % 3 == 0) {
        int destsize = size / 3;
        Triple *dest = (Triple *) malloc(destsize * sizeof(Triple));
        int i;
        for (i = 0; i < destsize; i++) {
            Triple *cur = &(dest[i]);
            int start = i * 3;
            cur -> a = &a[start];
            cur -> b = &a[start + 1];
            cur -> c = &a[start + 2];
        }
        return dest;
    }
    return NULL;
}

int test(void)
{
    int a[]={10,20,30,40,50,60};
    Triple *p = f(a, 5);
    if(p != NULL ) {
        return FALSE;
    }
    p = f(a, 6);
    return p -> a == a &&
        p -> b == &a[1] &&
        p -> c == &a[2] &&
        p[1].a == &a[3] &&
        p[1].b == &a[4] &&
        p[1].c == &a[5];
}

int main(void)
{
    printf("%s\n", test()? "Test passes." : "Test failure.");
    return 0;
} 
