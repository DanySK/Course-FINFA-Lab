/*
 * functions.h
 *
 *  Created on: Jan 17, 2013
 *      Author: Danilo Pianini
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "point.h"
#include <stdlib.h>
#include <math.h>
#include <glib.h>

typedef double (*function_t)(double x);
/*
 * A function_t is a structure made of a name and a function
 */
typedef struct function_t {
	char *name;
	/*
	 * This function computes the itself values in the range [min, max] with
	 * interval "precision". The result is stored in the last argument.
	 * The number of samples generated is returned as result.
	 */
	function_t f;
} function;

function* functions;
int functions_number;

void init_functions(void);

unsigned int compute(function_t f, double min, double max, double precision, GArray *points);

#endif /* FUNCTIONS_H_ */
