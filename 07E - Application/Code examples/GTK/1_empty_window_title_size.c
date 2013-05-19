#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "Empty Window");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *app;
	int status;
	/*
	 * Creates a new GApplication instance.
	 * If non-NULL, the application id must be valid. See
	 * g_application_id_is_valid().
	 * If no application ID is given then some features of GApplication (most
	 * notably application uniqueness) will be disabled.
	 */
	app = gtk_application_new("it.unibo.EmptyWindow", G_APPLICATION_FLAGS_NONE);
	/*
	 * Connects a GCallback function to a signal for a particular object.
	 * The handler will be called before the default handler of the signal.
	 *
	 * It is mandatory to associate a callback function to the signal
	 * "activate", which is the main entry point of a GTK+ application.
	 */
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	/*
	 * This function is intended to be run from main() and its return value is
	 * intended to be returned by main().
	 * Although you are expected to pass the argc, argv parameters from main()
	 * to this function, it is possible to pass NULL if argv is not available
	 * or commandline handling is not required.
	 */
	status = g_application_run(G_APPLICATION(app), 0, NULL );
	/*
	 * Decreases the reference count of object. When its reference count drops
	 * to 0, the object is finalized (i.e. its memory is freed).
	 */
	g_object_unref(app);
	return status;
}
