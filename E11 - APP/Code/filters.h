/*
 * filters.h
 *
 *  Created on: Jan 18, 2013
 *      Author: Danilo Pianini
 */

#ifndef FILTERS_H_
#define FILTERS_H_

#include "point.h"
#include <stdlib.h>
#include <stdio.h>
#include <glib.h>

/*
 * Defines a type for the filter functions: given two array of points, it populates the second with data from the previous
 */
typedef void (*filter_t)(GArray *points, GArray *filtered);

/*
 * A struct filter is a name along with a filter function.
 */
typedef struct filter {
	char *name;
	filter_t filter_function;
} filter;

/*
 * Array of fliters
 */
filter* filters;
/*
 * Number of defined filters
 */
int filters_number;
/*
 * Function that initializes the library, to call once.
 */
void init_filters(void);
#endif /* FILTERS_H_ */
