#include <stdio.h>

int fattoriale(int n){
    if (n<=1){
        return 1;
    } 
    return n*fattoriale(n-1);
}

int main(){
    int f=fattoriale2(5);
    printf("Il fattoriale di 5 e' %d",f);
}
