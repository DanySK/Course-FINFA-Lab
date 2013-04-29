// nprimi.c

#include <stdio.h>
#include <math.h>

int nprimi(int);

/* Costruire la funzione nprimi riportata come prototipo, che
 * preso in ingresso un numero 'n' maggiore di zero, stampa
 * a video tutti i primi 'n' numeri primi, ritornando l'n-esimo.
 * 
 */

int nprimi(int n){
   int c,i;
   for(i=1,c=1;n-->0;i++,c++){
      for (;!primo(c);c++);
      printf("Trovato il %d-esimo primo: %d\n",i,c);
   }
   return --c;
}

int primo(int n){
   int k,s=sqrt(n);
   for(k=2;k<=s;k++)
     if (n%k==0) return 0;
   return 1;
}

int test(){
    return nprimi(1)==1 &&
           nprimi(2)==2 &&
           nprimi(3)==3 &&
           nprimi(4)==5 &&
           nprimi(5)==7 &&
           nprimi(6)==11 &&
           nprimi(7)==13 &&
           nprimi(10000)==104723;
}


int main(){
    printf("Il risultato del test è %s\n", test()?"true":"false");
}
 
