// bit_lib.c

#include <stdio.h>
#include "bit_lib.h"

int singoletto(int b,int n){
    return n << b;
}

int unione(int set1,int set2){
    return set1 | set2;
}

int intersezione(int set1,int set2){
    return set1 & set2;
}

int leggi(int set,int b){
    return intersezione(set,singoletto(b,1)) != 0;
}

int scrivi(int set,int b,int n){
    return unione(set,singoletto(b,n));
}
// stampa a video la sequenza di bit, senza "a capo"
void stampa(int set){
    int i;
    for (i=NBIT;--i>=0;) printf("%d",leggi(set,i));
}