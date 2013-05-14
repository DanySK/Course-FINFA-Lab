#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex.h"

int main(void){ 
    Complex *c1=complex_new(10.0,20.0); 
    Complex *c2=complex_new(11.0,21.0);   
    Complex *c3=complex_add(c1,c2);   
    complex_add_to(c1,c2);
    char *s1 = complex_to_string(c1);
    char *s2 = complex_to_string(c2);
    char *s3 = complex_to_string(c3); 
    printf("c1: %s, c2: %s, c3: %s\n", s1, s2, s3); 
    return 0;
} 
