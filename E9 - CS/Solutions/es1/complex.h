#ifndef COMPLEX_H
#define COMPLEX_H

struct complex { 
    double re; 
    double im; 
}; 
typedef struct complex Complex; 

Complex *complex_new(double re,double im);

Complex *complex_add(Complex *c1,Complex *c2);

void complex_add_to(Complex *c1,Complex *c2);

char *complex_to_string(Complex *c);

unsigned int complex_size;

double complex_abs_square(Complex *c);

Complex *complex_find_biggest(Complex *array, int size);

#endif
