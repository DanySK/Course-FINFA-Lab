/*
 * filters.c
 *
 *  Created on: Jan 18, 2013
 *      Author: Danilo Pianini
 */

#include "filters.h"

/*
 * Empties the passed GArrray
 */
static void cleanup(GArray *filtered) {
	if (filtered->len > 0) {
		g_array_remove_range(filtered, 0, filtered->len);
	}
}

void same(GArray *points, GArray *filtered) {
	cleanup(filtered);
	int i;
	for (i = 0; i < points->len; i++) {
		g_array_append_val(filtered, g_array_index(points, Point2D, i));
	}
}

void invert(GArray *points, GArray *filtered) {
	cleanup(filtered);
	int i;
	for (i = 0; i < points->len; i++) {
		Point2D pto = g_array_index(points, Point2D, i) ;
		Point2D pt;
		pt.x = pto.x;
		pt.y = -pto.y;
		g_array_append_val(filtered, pt);
	}
}

void onlypos(GArray *points, GArray *filtered) {
	cleanup(filtered);
	int i;
	for (i = 0; i < points->len; i++) {
		Point2D pto = g_array_index(points, Point2D, i) ;
		Point2D pt;
		pt.x = pto.x;
		pt.y = pto.y > 0 ? pto.y : 0;
		g_array_append_val(filtered, pt);
	}
}

void integrate(GArray *points, GArray *filtered) {
	cleanup(filtered);
	if(points -> len > 1) {
		int i;
		double c = 0;
		for (i = 0; i < points->len-1; i++) {
			Point2D pt1 = g_array_index(points, Point2D, i) ;
			Point2D pt2 = g_array_index(points, Point2D, i+1) ;
			Point2D pt;
			pt.x = pt1.x;
			c += (pt1.y+pt2.y)/2*(pt2.x-pt1.x);
			pt.y = c;
			g_array_append_val(filtered, pt);
		}
	}
}

void init_filters(void) {
	/*
	 * How many filters are defined
	 */
	filters_number = 4;
	/*
	 * Allocate memory for them
	 */
	filters = (filter*) malloc(sizeof(filter) * filters_number);

	/*
	 * Instance all the filters
	 */
	filters[0].name = "Unaltered";
	filters[0].filter_function = same;

	filters[1].name = "Invert";
	filters[1].filter_function = invert;

	filters[2].name = "Only positive";
	filters[2].filter_function = onlypos;

	filters[3].name = "Integrate";
	filters[3].filter_function = integrate;

}

