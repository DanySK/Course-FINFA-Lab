#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(void){ 
	int a[4]={10, 20, 30, 40};
	List *la = list_from_array(a, 4);
	List *lb = list_cons(50, list_cons(60, list_nil()));
	printf("list a: %s\n", list_to_string(la));
	printf("list b: %s\n", list_to_string(lb));
	printf("list a contains %d elements\n", list_length(la));
	printf("list b contains: %d elements\n", list_length(lb));
	list_append_to(la,lb);
	printf("Result of appending b to a: %s\n", list_to_string(la));
	printf("New size: %d\n", list_length(la));
	printf("Is 10 in la? %s\n", list_search(la, 10) ? "Yes" : "No");
	printf("Is 40 in la? %s\n", list_search(la, 40) ? "Yes" : "No");
	printf("Is 60 in la? %s\n", list_search(la, 60) ? "Yes" : "No");
	printf("Is 11 in la? %s\n", list_search(la, 11) ? "Yes" : "No");
	List *lc = list_get(la, 20);
	printf("list c: %s\n", list_to_string(lc));
	List *ld = list_get(la, 40);
	printf("list d: %s\n", list_to_string(ld));
	
	int b[10] = {1, 1, 2, 3, 4, 5, 0, 7, 8, 9};
	la = list_from_array(b, 10);
	printf("list before cut: %s\n", list_to_string(la));
	list_cut_zero(la);
	printf("cut list: %s\n", list_to_string(la));
	
	return 0;
} 








