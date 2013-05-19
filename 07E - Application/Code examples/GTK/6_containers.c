#include <gtk/gtk.h>
#include "colorfactory.h"

GtkWidget *button, *drawing_area;

int draw_circle = TRUE;

static char *getLabel(void) {
	return draw_circle ? "Click to draw a square" : "Click to draw a circle";
}

static void clicked(GtkWidget *widget, gpointer data) {
	draw_circle = !draw_circle;
	gtk_button_set_label(GTK_BUTTON(button), getLabel());
	/*
	 * Forces a redraw
	 */
	gtk_widget_queue_draw_area(GTK_WIDGET(drawing_area), 0, 0, 5000, 5000);
}

gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
	/*
	 * Widget current size computation
	 */
	int width = gtk_widget_get_allocated_width(widget);
	int height = gtk_widget_get_allocated_height(widget);
	cairo_rectangle(cr, 0, 0, width, height);
	gdk_cairo_set_source_rgba(cr, color_white);
	cairo_fill(cr);
	if (draw_circle) {
		cairo_arc(cr, width / 2, height / 2, (width > height ? height : width) / 3, 0, 360.0);
	} else {
		cairo_rectangle(cr, width / 4, height / 4, width / 2, height / 2);
	}
	gdk_cairo_set_source_rgba(cr, color_black);
	cairo_fill(cr);
	return FALSE;
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window, *layout;
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "Drawing area");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 500);

	drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(drawing_area, 500, 500);
	g_signal_connect(G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), NULL);

	button = gtk_button_new_with_label(getLabel());
	g_signal_connect(button, "clicked", G_CALLBACK (clicked), NULL);

	layout = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_add(GTK_CONTAINER (layout), button);
	gtk_container_add(GTK_CONTAINER (layout), drawing_area);
	gtk_container_add(GTK_CONTAINER (window), layout);

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
