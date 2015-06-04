#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
    
/* 
 * Realizzare la funzione reduce qui sotto indicata, che dato un array di double in ingresso, la sua dimensione, un valore
 * di default, e il puntatore a una funzione f da coppie di double a double, calcola il risultato dell'applicazione di f dal
 * primo all'ultimo elemento dell'array. Il valore di default è il valore che andrà restituito qualora l'array in ingresso fosse
 * vuoto.
 * Ad esempio, se l'array avesse elementi a0 a1 a2 a3, il valore di default fosse v, e l'operazione di f fosse la somma, la
 * funzione reduce darebbe in uscita il risultato di:
 * 
 * a0+a1+a2+a3+a4  (calcolata da sinistra a destra)
 * 
 * Come riferimento si consideri che l'esecuzione del test deve fornire risultato positivo.
 */

double reduce(double *a, int size, double defVal, double (*f)(double, double))
{
    return 0;
}

double sum(double a, double b)
{
    return a + b;
}

double multiply(double a, double b)
{
    return a * b;
}
double max(double a, double b)
{
    return a > b ? a : b;
}
double min(double a, double b)
{
    return a < b ? a : b;
}

int test(){
     double a[4]={100.56, 22.36, 5.02, 2.326};
     return reduce(a, 4, 0, sum) == 130.266 &&
        reduce(a, 4, 10, sum) == 130.266 &&
        reduce(a, 1, 1, sum) == 100.56 &&
        reduce(a, 0, 35.2, multiply) == 35.2 &&
        reduce(a, 2, 0, multiply) == 2248.5216 &&
        reduce(a, 4, 1000, max) == 100.56&&
        reduce(a, 2, 1000, max) == 100.56 &&
        reduce(a, 0, 1000, max) == 1000 &&
        reduce(a, 0, 1000, min) == 1000 &&
        reduce(a, 4, -15, min) == 2.326 &&
        reduce(a, 4, 1000, min) == 2.326;
}

int main(){
     printf("%s\n", test() ? "Test passes." : "Test fails.");
     return 0;
}

