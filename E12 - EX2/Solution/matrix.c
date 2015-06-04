#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*  Realizzare la funzione sotto riportata che preso in ingresso un intero 'size' produce in uscita una matrice "size x size"
 * di interi, del tipo (caso size=5):
 * 
 * 0  0  0  0  1
 * 0  0  0  0  0
 * 0  0  2  0  0
 * 0  0  0  0  0
 * 3  0  0  0  0
 * 
 * Ossia una matrice di zeri che contenga, nella diagonale minore, dei numeri alternati a zeri, a partire da 1, contando a
 * partire dalla prima riga.
 * 
 * Come riferimento si consideri che l'esecuzione del test deve fornire risultato positivo. Si ricordi che una matrice va creata
 * nello heap, allocando lo spazio per ogni riga e per un 'array di righe' (ossia la matrice stessa).
 */
 
int array_equals(int a[], int b[], int size);

int **f(int size)
{
    int **res = (int **) malloc(size * sizeof(int *));
    int i;
    for (i = 0; i < size; i++) {
        res[i] = (int *) malloc(size * sizeof(int));
        int j;
        for (j = 0; j < size; j++) {
            /*
             * Trick explained:
             * 
             * i == size - 1 - j  --> returns 1 when we are on the minor diagonal
             * 
             * i % 2 == 0 --> returns 1 when we are on a row with even index
             * 
             * Those two conditions, combined with an &&, mean that we would
             * write 1 on all the elements on the minor diagonal on alternate
             * lines. Still, we need to progressively increase those 1s.
             * 
             * We must write 1 at line 0, 2 at line 2, 3 at line 4, 4 at line 6...
             * So the formula is line/2+1. We already have a formula that
             * returns 1 only where we should write a number and 0 otherwise,
             * so we can just multiply.
             * 
             * NOTE: this exercise can be solved using if(s) or more indexes,
             * though this is the most compact solution I could think of.
             */
            res[i][j] = (i == size - 1 - j && i % 2 == 0) * (i / 2 + 1);
        }
    }
    return res;
}

int test()
{
    int o3[3][3] = {{0, 0, 1}, {0, 0, 0}, {2, 0, 0}};
    int **r3 = f(3);
    int i;
    for (i = 0; i < 3; i++) {
        if (!array_equals(o3[i], r3[i], 3)) {
            return FALSE;
        }
    }
    int o6[6][6] = {{0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 3, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
    int **r6 = f(6);
    for (i = 0; i < 6; i++) {
        if (!array_equals(o6[i], r6[i], 6)) {
            return FALSE;
        }
    }
    return TRUE;
}

int main(void)
{
    printf("%s\n", test()? "Test passes." : "Test fails.");
    return !test();
}

int array_equals(int a[], int b[], int size)
{
    while (size--) {
        if (a[size]!=b[size]) {
            return FALSE;
        }
    }
    return TRUE;
}
 
