#include <stdio.h> 
#include <stdlib.h>
#include "complex.h"

unsigned int complex_size=sizeof(Complex);

Complex *complex_new(double re,double im){ 
    Complex *c=(Complex *)malloc(complex_size); 
    c->re=re; 
    c->im=im; 
    return c; 
}

Complex *complex_add(Complex *c1,Complex *c2){ 
    return complex_new(c1->re+c2->re,c1->im+c2->im); 
}

void complex_add_to(Complex *c1,Complex *c2){ 
    c1->re += c2->re; 
    c1->im += c2->im; 
} 

char *complex_to_string(Complex *c){ 
    char *ch=malloc(100);
    // sprintf lavora come printf, ma l'output finisce su ch!
    sprintf(ch,"%f+%fi)",c->re,c->im); 
    return ch; 
} 
