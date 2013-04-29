// bit_lib.h

#define UNO 1
#define ZERO 0
#define NBIT sizeof(int)*8

// costruisce un set col solo bit b-esimo posto a n
int singoletto(int b,int n);

// legge e ritorna il b-esimo bit di set 
int leggi(int set,int b);

// modifica il b-esimo bit di set ponendolo a n, torna il risultato
int scrivi(int set,int b,int n);

// ritorna l'unione dei due set di bit set1 e set2
int unione(int set1,int set2);

// ritorna l'intersezione dei due set di bit set1 e set2
int intersezione(int set1,int set2);

// stampa a video la sequenza di bit, senza "a capo"
void stampa(int set);