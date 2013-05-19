#include <gtk/gtk.h>

GtkWidget *button;

static void pressed(GtkWidget *widget, gpointer data) {
	gtk_button_set_label(GTK_BUTTON(button), "Pressed");
}

static void released(GtkWidget *widget, gpointer data) {
	gtk_button_set_label(GTK_BUTTON(button), "Released");
}

static void enter(GtkWidget *widget, gpointer data) {
	gtk_button_set_label(GTK_BUTTON(button), "Mouse Entered");
}

static void leave(GtkWidget *widget, gpointer data) {
	gtk_button_set_label(GTK_BUTTON(button), "Mouse Left");
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "A button");
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
	button = gtk_button_new_with_label("This is a button");
	gtk_container_add(GTK_CONTAINER (window), button);
	/*
	 * Associate a callback to a signal. See all the signal for the buttons
	 * at https://developer.gnome.org/gtk3/3.2/GtkButton.html
	 */
	g_signal_connect(button, "enter", G_CALLBACK (enter), NULL);
	g_signal_connect(button, "leave", G_CALLBACK (leave), NULL);
	g_signal_connect(button, "pressed", G_CALLBACK (pressed), NULL);
	g_signal_connect(button, "released", G_CALLBACK (released), NULL);
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
