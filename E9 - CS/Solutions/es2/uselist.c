#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(void){ 
	int a[4]={10,20,30,40};
	List *la = list_from_array(a,4);
	List *lb = list_cons(50,list_cons(60,list_nil()));
	printf("lista a: %s\n",list_to_string(la));
	printf("lista b: %s\n",list_to_string(lb));
	printf("dimensione lista a: %d\n", list_length(la));
	printf("dimensione lista b: %d\n", list_length(lb));
	list_append_to(la,lb);
	printf("nuova lista a (APPEND a e b): %s\n",list_to_string(la));
	printf("dimensione lista a modificata: %d\n", list_length(la));
	printf("è presente l'elemento 10 in la? %s\n", list_search(la,10) ? "Sì" : "No");
	printf("è presente l'elemento 40 in la? %s\n", list_search(la,40) ? "Sì" : "No");
	printf("è presente l'elemento 60 in la? %s\n", list_search(la,60) ? "Sì" : "No");
	printf("è presente l'elemento 11 in la? %s\n", list_search(la,11) ? "Sì" : "No");
	List *lc = list_get(la,20);
	printf("lista c: %s\n",list_to_string(lc));
	List *ld = list_get(la,40);
	printf("lista d: %s\n",list_to_string(ld));
	
	int b[10]={1,1,2,3,4,5,0,7,8,9};
	la = list_from_array(b,10);
	printf("lista prima del taglio: %s\n", list_to_string(la));
	list_cut_zero(la);
	printf("lista tagliata: %s\n", list_to_string(la));
	
	return 0;
} 








