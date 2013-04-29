// uselib.c

#include <stdio.h>
#include "bit_lib.h"

main(){
    int set1,set2=0;
    int i=0;
    for (;i<NBIT;i+=2) set1=scrivi(set1,i,UNO);
    for (i=1;i<NBIT;i+=2) set2=scrivi(set2,i,UNO);
    stampa(set1); printf("\n");
    stampa(set2); printf("\n");
    stampa(unione(set1,set2)); printf("\n");
    stampa(intersezione(set1,set2)); printf("\n");
}