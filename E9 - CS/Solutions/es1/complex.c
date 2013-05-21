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

double complex_abs_square(Complex *c){
    return c->re * c->re + c->im * c->im;
}

Complex *complex_find_biggest(Complex *array, int size){
    if(size <= 0) {
        return NULL;
    }
    int i;
    Complex *res = array;
    for(i = 0; i< size; i++) {
        if(complex_abs_square(array + i) > complex_abs_square(res)) {
            res = array + i;
        }
    }
    return res;
}

