/*
 * functions.c
 *
 *  Created on: Jan 17, 2013
 *      Author: Danilo Pianini
 */

#include "functions.h"

static double x(double x) {
	return x;
}

unsigned int compute(function_t f, double min, double max, double precision, GArray *points) {
	unsigned int samples = (max - min) / precision + 1;
	unsigned int i;
	for (i = 0; i < samples; i++) {
		double v = min + i * precision;
		Point2D pt;
		pt.x = v;
		pt.y = f(v);
		g_array_append_val(points, pt);
	}
	return samples;
}

static double sinx(double x) {
	return sin(x);
}

static double ex(double x) {
	return exp(x);
}

static double tanx(double x) {
	return tan(x);
}

void init_functions(void) {
	functions_number = 4;

	functions = (function *) malloc(sizeof(function) * functions_number);
	functions[0].name = "y = x";
	functions[0].f = x;

	functions[1].name = "y = sin(x)";
	functions[1].f = sinx;

	functions[2].name = "y = e^(x)";
	functions[2].f = ex;

	functions[3].name = "y = tan(x)";
	functions[3].f = tanx;

}
