#include <stdio.h>

#define FALSE 0
#define TRUE 1


/*  
 Realizzare in versione iterativa la funzione f sotto riportata che riconosce se l'array in ingresso
 contiene una frase della grammatica 0{1}2.
 Si consideri anche che l'esecuzione del test (eseguita dalla funzione main) deve riportare 
 il risultato true (1 nel caso specifico del C). 
*/

int f(int a[],int size){
	if(size <2 || a[0]!=0 || a[size-1]!=2){
		return FALSE;
	}
	int i;
	for(i=1;i<size-1 && a[i]==1;i++);
	return i == size-1;
}
    
    
/* test deve restituire 1 (TRUE)*/
int test(void){
	
	int a[] = {0,2};
	int b[] = {0,1,1,1,1,2};
	int c[] = {0,1,2};
	int d[] = {0,1,1,2};
	
	int s[] = {0};
	int g[] = {1};
	int h[] = {0,1};
	int i[] = {2};
	int l[] = {0,2,2};
	int m[] = {0,1,1,1};
	int e[] = {3,0,1,1,2,0,1,1,2};
	int n[] = {0,1,1,2,0,1,1,2,3};	
	int v[0];
	
	 
	return f(a,2)  && 
	f(b,6)  &&
	f(c,3)  &&
	f(d,4)  &&
	!f(v,0) &&
	!f(s,1) &&
	!f(g,1) &&
	!f(h,2) &&
	!f(i,1) &&
	!f(l,3) &&
	!f(m,4) &&
	!f(e,9) &&
	!f(n,9);		
}

    
int main(void){
    printf("%s\n",test() ? "true" : "false");
    return 0;
}
    
    

