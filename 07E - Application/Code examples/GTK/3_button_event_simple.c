#include <gtk/gtk.h>

/*
 * This is a callback function. The data arguments are ignored
 * in this example.
 */
static void print_hello(GtkWidget *widget, gpointer data) {
	printf("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window, *button;
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "A button");
	button = gtk_button_new_with_label("This is a button");
	gtk_container_add(GTK_CONTAINER (window), button);
	/*
	 * Associate a callback to a signal. See all the signal for the buttons
	 * at https://developer.gnome.org/gtk3/3.2/GtkButton.html
	 */
	g_signal_connect(button, "clicked", G_CALLBACK (&print_hello), NULL);
	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *app;
	int status;
	app = gtk_application_new("it.unibo.EmptyWindow", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), 0, NULL );
	g_object_unref(app);
	return status;
}
