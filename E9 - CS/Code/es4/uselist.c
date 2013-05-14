 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
 * implementare qui la void filter(int *) 
 */

int main(void){ 
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  List *la = list_from_array(a,10);
  printf("lista: %s\n",list_to_string(la));
  apply_to_all(la, filter);
  printf("lista filtrata: %s\n",list_to_string(la));
  int expected[10]={1,0,3,0,5,0,7,0,9,0};
  printf("risultato atteso: %s\n", list_to_string(list_from_array(expected, 10)));
  return 0;
} 








