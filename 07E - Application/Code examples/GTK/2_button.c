#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window, *button;
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "A button");
	/*
	 * Create a button
	 */
	button = gtk_button_new_with_label("This is a button");
	/*
	 * Put the button in the window
	 */
	gtk_container_add (GTK_CONTAINER (window), button);
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
