#include <stdio.h>

#define FALSE 0
#define TRUE 1


/*  
Realizzare il riconoscitore precedente in versione ricorsiva 
*/

int ric(int a[], int size) {
	return FALSE;
}
  
    
int test(void) {
	
	int a[] = {0, 2};
	int b[] = {0, 1, 1, 1, 1, 2};
	int c[] = {0, 1, 2};
	int d[] = {0, 1, 1, 2};
	
	int s[] = {0};
	int g[] = {1};
	int h[] = {0, 1};
	int i[] = {2};
	int l[] = {0, 2, 2};
	int m[] = {0, 1, 1, 1};
	int e[] = {3, 0, 1, 1, 2, 0, 1, 1, 2};
	int n[] = {0, 1, 1, 2, 0, 1, 1, 2, 3};	
	int v[0];
	
	 
	return ric(a,2)  && 
	ric(b,6)  &&
	ric(c,3)  &&
	ric(d,4)  &&
	!ric(v,0) &&
	!ric(s,1) &&
	!ric(g,1) &&
	!ric(h,2) &&
	!ric(i,1) &&
	!ric(l,3) &&
	!ric(m,4) &&
	!ric(e,9) &&
	!ric(n,9);		
}

    
int main(void) {
	printf("%d\n", test());
}
    
    

