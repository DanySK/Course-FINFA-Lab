#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex.h"

#define TESTSIZE 3

int main(void){ 
    Complex *c1=complex_new(10.0,20.0); 
    Complex *c2=complex_new(11.0,21.0);   
    Complex *c3=complex_add(c1,c2);   
    complex_add_to(c1,c2);
    char *s1 = complex_to_string(c1);
    char *s2 = complex_to_string(c2);
    char *s3 = complex_to_string(c3); 
    printf("c1: %s, c2: %s, c3: %s\n", s1, s2, s3);
    
    Complex *array = (Complex *) malloc(TESTSIZE * sizeof(Complex));
    int i;
    printf("Array:\n [ ");
    for(i = 0; i < TESTSIZE; i++) {
        array[i].re = (double)rand()/(double)RAND_MAX + rand();
        array[i].im = (double)rand()/(double)RAND_MAX + rand();
	printf("(%s) ",complex_to_string(array+i));
    }
    printf("]\nThe one with the biggest module is: %s\n", complex_to_string(complex_find_biggest(array, TESTSIZE)));
    
    return 0;
} 
