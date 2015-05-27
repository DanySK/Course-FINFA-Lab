#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*  Realizzare la funzione sotto riportata che preso in ingresso un intero 'size' produce in uscita una matrice "size x size"
 * di interi, del tipo (caso size=5):
 * 
 * 1  1  1  1  1
 * 1  0  0  1  1
 * 1  0  1  0  1
 * 1  1  0  0  1
 * 1  1  1  1  1
 * 
 * Ossia una matrice di zeri che contenga degli 1 nel "contorno" e nella diagonale minore.
 * 
 * Come riferimento si consideri che l'esecuzione del test deve fornire risultato positivo. Si ricordi che una matrice va creata
 * nello heap, allocando lo spazio per ogni riga e per un 'array di righe' (ossia la matrice stessa).
 */
 
int array_equals(int a[], int b[], int size);

int **f(int size)
{
    return NULL;
}

int test()
{
    int o3[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    int **r3 = f(3);
    int i;
    for (i = 0; i < 3; i++) {
        if (!array_equals(o3[i], r3[i], 3)) {
            return FALSE;
        }
    }
    int o6[6][6] = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 1}, {1, 0, 0, 1, 0, 1}, {1, 0, 1, 0, 0, 1}, {1, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};
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
    printf("%s\n",test()? "Test passes." : "Test fails.");
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
 
