/*
 * colorfactory.c
 *
 *  Created on: Jan 15, 2013
 *      Author: Danilo Pianini
 */
#include "colorfactory.h"

static GdkRGBA* gen_color_white(void) {
	GdkRGBA *color = (GdkRGBA *) malloc(sizeof(GdkRGBA));
	color->red = 1.0;
	color->green = 1.0;
	color->blue = 1.0;
	color->alpha = 1.0;
	return color;
}

static GdkRGBA* gen_color_black(void) {
	GdkRGBA *color = (GdkRGBA *) malloc(sizeof(GdkRGBA));
	color->red = 0;
	color->green = 0;
	color->blue = 0;
	color->alpha = 1.0;
	return color;
}

static GdkRGBA* gen_color_blue(void) {
	GdkRGBA *color = (GdkRGBA *) malloc(sizeof(GdkRGBA));
	color->red = 0;
	color->green = 0;
	color->blue = 1.0;
	color->alpha = 1.0;
	return color;
}

void init_color_factory(void) {
	color_white = gen_color_white();
	color_black = gen_color_black();
	color_blue = gen_color_blue();
}

