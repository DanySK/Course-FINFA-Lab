#include <gtk/gtk.h>
#include "colorfactory.h"

GtkWidget *drawing_area;

gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
	/*
	 * Widget current size computation
	 */
	const int width = gtk_widget_get_allocated_width(widget);
	const int height = gtk_widget_get_allocated_height(widget);

	cairo_rectangle(cr, 0, 0, width, height);
	gdk_cairo_set_source_rgba(cr, color_white);
	cairo_fill(cr);

	cairo_arc(cr,width/2,height/2,(width > height ? height : width ) / 3, 0 , 360.0);
	gdk_cairo_set_source_rgba(cr, color_black);
	cairo_fill(cr);

	cairo_arc(cr,width/2,height/2,(width > height ? height : width ) / 2.5, 0 , 360.0);
	gdk_cairo_set_source_rgba(cr, color_blue);
	cairo_stroke(cr);

	return FALSE;
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "Drawing area");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

	drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(drawing_area, 500, 500);
	g_signal_connect(G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), NULL);
	gtk_container_add(GTK_CONTAINER (window), drawing_area);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	init_color_factory();
	GtkApplication *app;
	int status;
	app = gtk_application_new("it.unibo.EmptyWindow", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), 0, NULL );
	g_object_unref(app);
	return status;
}
