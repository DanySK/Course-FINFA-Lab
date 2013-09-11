/*
 ============================================================================
 Name        : FunctionDrawer.c
 Author      : Danilo Pianini
 Version     : 2013
 Copyright   : GPL
 Description : Simple application in GTK+3
 ============================================================================
 */

#ifndef MAXVAL
#define MAXVAL 1000
#endif

#ifndef MAX_SCREEN_RESOLUTION
#define MAX_SCREEN_RESOLUTION 10000
#endif

/*
 * #include Includes system header files if used with <>, while searches the
 * local path if "" are used.
 */
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <math.h>
#include <gtk/gtk.h>
#include "colorfactory.h"
#include "functions.h"
#include "filters.h"

/*
 * Area to draw
 */
static double minx = -10.0, maxx = 10.0, miny = -10.0, maxy = 10;
/*
 * Interval between the ticks in the axes and width
 */
static const int DIVS = 8, TICKWIDTH = 5;
/*
 * Size of the drawing area
 */
static guint width, height;
/*
 * Numeric id for the current active function and filter
 */
static gint active_function, active_filter;
/*
 * Array of points for the current function and filter
 */
static GArray *pts, *filtered;
/*
 * Widgets for this program: a window, two box layouts and a drawing area
 */
static GtkWidget *window, *functions_box, *filters_box, *drawing_area;
/*
 * The adjustments allow to define how a slider should work. See https://developer.gnome.org/gtk3/3.5/GtkAdjustment.html
 */
static GtkAdjustment *minx_adj, *maxx_adj, *miny_adj, *maxy_adj, *precision_adj;

/*
 * Converts an x value in screen coordinates (pixels)
 */
int xToScreen(double x) {
	if (x > MAXVAL) {
		return MAX_SCREEN_RESOLUTION;
	}
	if (x < -MAXVAL) {
		return -MAX_SCREEN_RESOLUTION;
	}
	return (int) ((x - minx) * width / (maxx - minx));
}

/*
 * Converts an y value in screen coordinates (pixels)
 */
int yToScreen(double y) {
	/*
	 * y coordinates are from top to bottom!
	 */
	if (y > MAXVAL) {
		return -MAX_SCREEN_RESOLUTION;
	}
	if (y < -MAXVAL) {
		return MAX_SCREEN_RESOLUTION;
	}
	return (int) (height - ((y - miny) * height / (maxy - miny)));
}

/*
 * In this function, given a cairo_t, we draw on the drawing area the currently active function.
 */
static void draw_function(cairo_t *cr) {
	/*
	 * At least two points are needed
	 */
	if (pts->len >= 2 && filtered->len >= 2) {
		/*
		 * Draw the function in blue
		 */
		unsigned int i;
		for (i = 0; i < pts->len - 1; i++) {
			cairo_move_to(cr, xToScreen(g_array_index(pts, Point2D, i) .x), yToScreen(g_array_index(pts, Point2D, i).y));
			cairo_line_to(cr, xToScreen(g_array_index(pts, Point2D, i+1).x), yToScreen(g_array_index(pts, Point2D, i+1).y));
		}
		gdk_cairo_set_source_rgba(cr, color_blue);
		cairo_stroke(cr);

		/*
		 * Draw the filtered function in red
		 */
		for (i = 0; i < filtered->len - 1; i++) {
			cairo_move_to(cr, xToScreen(g_array_index(filtered, Point2D, i) .x), yToScreen(g_array_index(filtered, Point2D, i).y));
			cairo_line_to(cr, xToScreen(g_array_index(filtered, Point2D, i+1).x), yToScreen(g_array_index(filtered, Point2D, i+1).y));
		}
		gdk_cairo_set_source_rgba(cr, color_red);
		cairo_stroke(cr);
	}
}

/*
 * Given a cairo_t, this function draws in the drawing area the two axes and their labels.
 */
static void draw_axes(cairo_t *cr) {
	gdk_cairo_set_source_rgba(cr, color_black);
	cairo_set_font_size(cr, 10);
	cairo_move_to(cr, 0, yToScreen(0));
	cairo_line_to(cr, width, yToScreen(0));
	cairo_move_to(cr, xToScreen(0), 0);
	cairo_line_to(cr, xToScreen(0), height);
	int i;
	const double xstep = (maxx - minx) / DIVS;
	const double ystep = (maxy - miny) / DIVS;
	for (i = 0; i <= DIVS; i++) {
		int xcoord = xToScreen(minx + xstep * i);
		int ycoord = yToScreen(miny + ystep * i);
		cairo_move_to(cr, xcoord, yToScreen(0) - TICKWIDTH);
		cairo_line_to(cr, xcoord, yToScreen(0) + TICKWIDTH);
		cairo_move_to(cr, xcoord - 15, yToScreen(0) + TICKWIDTH + 10);
		/*
		 * Buffer size:
		 * 3 chars for the decimals
		 * 5 chars for the integer
		 * 1 char for string termination (\0)
		 */
		char bufferx[9];
		sprintf(bufferx, "%5.3f", xstep * i + minx);
		cairo_show_text(cr, bufferx);
		cairo_move_to(cr, xToScreen(0) - TICKWIDTH, ycoord);
		cairo_line_to(cr, xToScreen(0) + TICKWIDTH, ycoord);
		cairo_move_to(cr, xToScreen(0) + TICKWIDTH + 1, ycoord + 6);
		char buffery[9];
		sprintf(buffery, "%5.3f", ystep * i + miny);
		cairo_show_text(cr, buffery);
	}
	cairo_stroke(cr);
}

/*
 * Draw callback: this function is called when a redraw request is generated for the drawing area.
 */
gboolean draw_callback(GtkWidget *widget, cairo_t *cr, gpointer data) {
	/*
	 * Widget current size computation
	 */
	width = gtk_widget_get_allocated_width(widget);
	height = gtk_widget_get_allocated_height(widget);
	/*
	 * White background
	 */
	cairo_rectangle(cr, 0, 0, width, height);
	gdk_cairo_set_source_rgba(cr, color_white);
	cairo_fill(cr);
	/*
	 * Draw axes. This code has been split in another function to improve code readability.
	 */
	draw_axes(cr);
	/*
	 * Draw function and filtered function. This code has been split in another function to improve code readability.
	 */
	draw_function(cr);
	return TRUE;
}

/*
 * Removes all the data from the function and filtered functions Point2D GArray.
 */
static void cleanup(void) {
	if (pts->len > 0) {
		g_array_remove_range(pts, 0, pts->len);
	}
	if (filtered->len > 0) {
		g_array_remove_range(filtered, 0, filtered->len);
	}
}

/*
 * Loads a data file in format:
 *
 * X0 Y0
 * X1 Y1
 * X... Y...
 * XN YN
 *
 */
static void load() {
	/*
	 * Clean up the current data
	 */
	cleanup();
	/*
	 * Detect the current window, to use as parent for the file chooser window
	 */
	GtkWidget *dialog;
	GtkWindow *parent = GTK_WINDOW(gtk_widget_get_parent_window(window));
	/*
	 * Ready-to-use file selector. See https://developer.gnome.org/gtk3/3.4/GtkFileChooser.html
	 */
	dialog = gtk_file_chooser_dialog_new("Open File", parent, GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL );
	/*
	 * If the user selected a file
	 */
	if (gtk_dialog_run(GTK_DIALOG (dialog) ) == GTK_RESPONSE_ACCEPT) {
		/*
		 * Get the file name
		 */
		char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER (dialog) );
		/*
		 * Open the file
		 */
		FILE *file = fopen(filename, "r");
		if (file == NULL ) {
			printf("Error Reading File\n");
		} else {
			double x, y;
			/*
			 * Scan the file, for each entry create a Point2D and add it to the function
			 */
			while (fscanf(file, "%lf %lf", &x, &y) == 2) {
				Point2D pt;
				pt.x = x;
				pt.y = y;
				g_array_append_val(pts, pt);
			}
			/*
			 * Close the file
			 */
			fclose(file);
		}
		/*
		 * We don't need filename any longer, let's free the memory
		 */
		free(filename);
	}
	/*
	 * We don't need the dialog any longer
	 */
	gtk_widget_destroy(dialog);
}

/*
 * This function must be called if something changed and, as a consequence, the draw must be updated.
 */
static void redraw(GtkApplication *app, gpointer user_data) {
	/*
	 * Clean previous results
	 */
	cleanup();
	/*
	 * Get current data from sliders
	 */
	maxx = gtk_adjustment_get_value(maxx_adj);
	minx = -gtk_adjustment_get_value(minx_adj);
	maxy = gtk_adjustment_get_value(maxy_adj);
	miny = -gtk_adjustment_get_value(miny_adj);
	active_function = gtk_combo_box_get_active(GTK_COMBO_BOX(functions_box) );
	active_filter = gtk_combo_box_get_active(GTK_COMBO_BOX(filters_box) );
	/*
	 * If no function of those predefined is selected, then load from file
	 */
	if (active_function >= functions_number) {
		load();
	} else {
		/*
		 * One of the built-in functions has been chosen
		 */
		function_t fun = functions[active_function].f;
		/*
		 * Compute the precision
		 */
		double precision = (maxx - minx) / gtk_adjustment_get_value(precision_adj);
		/*
		 * Use the function pointer to compute the values for each point
		 */
		compute(fun, minx, maxx, precision, pts);
	}
	/*
	 * Run the filter
	 */
	filter_t fil = filters[active_filter].filter_function;
	fil(pts, filtered);
	/*
	 * Schedule a redraw for the whole screen
	 */
	gtk_widget_queue_draw_area(GTK_WIDGET(drawing_area), 0, 0, MAX_SCREEN_RESOLUTION, MAX_SCREEN_RESOLUTION);
}

/*
 * Saves a data file in format:
 *
 * X0 Y0
 * X1 Y1
 * X... Y...
 * XN YN
 *
 */
static void save(GtkApplication *app, gpointer user_data) {
	/*
	 * Detect the current window, to use as parent for the file chooser window
	 */
	GtkWidget *dialog;
	GtkWindow *parent = GTK_WINDOW(gtk_widget_get_parent_window(window));
	/*
	 * Ready-to-use file selector. See https://developer.gnome.org/gtk3/3.4/GtkFileChooser.html
	 */
	dialog = gtk_file_chooser_dialog_new("Save File", parent, GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL );
	/*
	 * If the user selects an existing file, ask if she's sure she wants to overwrite
	 */
	gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER (dialog), TRUE);
	/*
	 * Set "result.txt" as default name
	 */
	gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER (dialog), "result.txt");
	/*
	 * If the users gave positive answer
	 */
	if (gtk_dialog_run(GTK_DIALOG (dialog) ) == GTK_RESPONSE_ACCEPT) {
		char *filename;
		/*
		 * Get the filename
		 */
		filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER (dialog) );
		/*
		 * Open the file in writing mode
		 */
		FILE *file = fopen(filename, "w");
		if (file != NULL ) {
			/*
			 * write the whole content of filtered onto file
			 */
			int i;
			for (i = 0; i < filtered->len && fprintf(file, "%lf %lf\n", g_array_index(filtered, Point2D, i) .x, g_array_index(filtered, Point2D, i).y); i++);
			if (i != filtered->len) {
				printf("Error Writing File\n");
			}
			/*
			 * Close the file
			 */
			fclose(file);
		} else {
			printf("Error Writing File\n");
		}
		/*
		 * We don't need filename any longer. Let's free memory.
		 */
		g_free(filename);
	}
	/*
	 * We don't need the dialog any longer
	 */
	gtk_widget_destroy(dialog);
}

/*
 * Builds the graphical application
 */
static void activate(GtkApplication *app, gpointer user_data) {
	/*
	 * Widget definition: two layouts, a button, and five sliders
	 */
	GtkWidget *hlayout, *rlayout, *save_button, *minx_scale, *maxx_scale, *miny_scale, *maxy_scale, *precision_scale;
	/*
	 * Values for the sliders
	 */
	gdouble v = 10, lower = 0.001, upper = MAXVAL, step = 0.1, page = 1, page_s = 1;
	/*
	 * Create the sliders
	 */
	minx_adj = gtk_adjustment_new(v, lower, upper, step, page, page_s);
	maxx_adj = gtk_adjustment_new(v, lower, upper, step, page, page_s);
	miny_adj = gtk_adjustment_new(v, lower, upper, step, page, page_s);
	maxy_adj = gtk_adjustment_new(v, lower, upper, step, page, page_s);
	precision_adj = gtk_adjustment_new(100, 10, 1000, 1, page, page_s);
	/*
	 * Create the window
	 */
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW (window), "FINF-A Function Drawer");
	gtk_window_set_default_size(GTK_WINDOW(window), 1024, 768);
	/*
	 * Create an horizontal layout. This will split the window in two
	 */
	hlayout = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
	/*
	 * Put the layout as widget for the window
	 */
	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(hlayout) );
	/*
	 * Create a new drawing area
	 */
	drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request(drawing_area, 768, 768);
	/*
	 * Associate the draw callback
	 */
	g_signal_connect(G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), NULL);
	/*
	 * Add the drawing area to the horizontal layout
	 */
	gtk_paned_add1(GTK_PANED(hlayout), drawing_area);
	/*
	 * Create a vertical layout
	 */
	rlayout = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	/*
	 * Add the vertical layout to the main layout. In this way, we will have the drawing area on the left and the content of this layout on the right.
	 */
	gtk_paned_add2(GTK_PANED(hlayout), rlayout);
	/*
	 * Functions combo box (similar to a multi-choice drop-down menu), see https://developer.gnome.org/gtk3/3.9/GtkComboBox.html
	 */
	functions_box = gtk_combo_box_text_new();
	/*
	 * Init the load option
	 */
	char *buffer = (char *) malloc(sizeof(char) * 5);
	sprintf(buffer, "Load");
	gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(functions_box), 0, buffer, "Load from file");
	/*
	 * Init the built-in functions
	 */
	int i;
	for (i = functions_number - 1; i >= 0; i--) {
		char *buffer = (char *) malloc(sizeof(char) * 3);
		sprintf(buffer, "%2d", functions_number - i - 1);
		gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(functions_box), 0, buffer, functions[i].name);
	}
	/*
	 * Set the first function as active
	 */
	active_function = 0;
	gtk_combo_box_set_active(GTK_COMBO_BOX(functions_box), active_function);
	/*
	 * If the selection changes, then redraw.
	 */
	g_signal_connect(functions_box, "changed", G_CALLBACK(redraw), NULL);
	/*
	 * Filters box, similar to previous
	 */
	filters_box = gtk_combo_box_text_new();
	for (i = filters_number - 1; i >= 0; i--) {
		char *buffer = (char *) malloc(sizeof(char) * 3);
		sprintf(buffer, "%2d", functions_number - i - 1);
		gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(filters_box), 0, buffer, filters[i].name);
	}
	active_filter = 0;
	gtk_combo_box_set_active(GTK_COMBO_BOX(filters_box), active_filter);
	g_signal_connect(filters_box, "changed", G_CALLBACK(redraw), NULL);
	/*
	 * Save button
	 */
	save_button = gtk_button_new_with_label("Save");
	/*
	 * On click, call save
	 */
	g_signal_connect(save_button, "clicked", G_CALLBACK(save), NULL);
	/*
	 * Use the adjustments to build the sliders
	 */
	minx_scale = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, minx_adj);
	maxx_scale = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, maxx_adj);
	miny_scale = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, miny_adj);
	maxy_scale = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, maxy_adj);
	precision_scale = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, precision_adj);
	/*
	 * If something changes, redraw
	 */
	g_signal_connect(minx_adj, "value-changed", G_CALLBACK(redraw), NULL);
	g_signal_connect(maxx_adj, "value-changed", G_CALLBACK(redraw), NULL);
	g_signal_connect(miny_adj, "value-changed", G_CALLBACK(redraw), NULL);
	g_signal_connect(maxy_adj, "value-changed", G_CALLBACK(redraw), NULL);
	g_signal_connect(precision_adj, "value-changed", G_CALLBACK(redraw), NULL);
	/*
	 * Populate the right side: put labels and all the components we've built above
	 */
	gtk_box_pack_start(GTK_BOX(rlayout), gtk_label_new("Base function"), TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), functions_box, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), gtk_label_new("Function filter"), TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), filters_box, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), gtk_label_new("Precision"), TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), precision_scale, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), gtk_label_new("Min X"), TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), minx_scale, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), gtk_label_new("Max X"), TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), maxx_scale, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), gtk_label_new("Min Y"), TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), miny_scale, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), gtk_label_new("Max Y"), TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), maxy_scale, TRUE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(rlayout), save_button, TRUE, FALSE, 0);
	/*
	 * Graphic done, show it on screen!
	 */
	gtk_widget_show_all(window);
	/*
	 * On close, destroy everything
	 */
	g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	/*
	 * Launch a first draw
	 */
	redraw(NULL, NULL );
}

/*
 * Initialize libraries and GArrays.
 */
static void init() {
	init_color_factory();
	init_functions();
	init_filters();
	pts = g_array_new(FALSE, FALSE, sizeof(Point2D));
	filtered = g_array_new(FALSE, FALSE, sizeof(Point2D));
}

int main(int argc, char **argv) {
	/*
	 * Initialize libraries
	 */
	init();
	/*
	 * Declare a new application
	 */
	GtkApplication *app;
	int status;
	/*
	 * Creates a new GApplication instance.
	 * If non-NULL, the application id must be valid. See
	 * g_application_id_is_valid().
	 * If no application ID is given then some features of GApplication (most
	 * notably application uniqueness) will be disabled.
	 */
	app = gtk_application_new("it.unibo.FunctionDrawer", G_APPLICATION_FLAGS_NONE);
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
