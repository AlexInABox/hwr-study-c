#include <gtk/gtk.h>

void draw_function(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer data) {

    double heightOffset = 0.1;
    double widthOffset = 0;

    cairo_move_to(cr, width * (0.25 +  widthOffset), height * (0.75 + heightOffset));
    cairo_line_to(cr, width * (0.25 +  widthOffset), height * (0.25 + heightOffset));
    cairo_line_to(cr, width * (0.50 +  widthOffset), height * (0.00 + heightOffset));
    cairo_line_to(cr, width * (0.75 +  widthOffset), height * (0.25 + heightOffset));
    cairo_line_to(cr, width * (0.75 +  widthOffset), height * (0.75 + heightOffset));
    cairo_line_to(cr, width * (0.25 +  widthOffset), height * (0.75 + heightOffset));
    cairo_line_to(cr, width * (0.75 +  widthOffset), height * (0.25 + heightOffset));
    cairo_line_to(cr, width * (0.25 +  widthOffset), height * (0.25 + heightOffset));
    cairo_line_to(cr, width * (0.75 +  widthOffset), height * (0.75 + heightOffset));

    cairo_set_source_rgb(cr, 216.0 / 255.0, 36.0 / 255.0, 37.0 / 255.0);
    cairo_set_line_width(cr, 4);
    cairo_stroke(cr);
}

void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "E9T5");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    GtkWidget *area = gtk_drawing_area_new();
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA (area), draw_function, NULL, NULL);
    gtk_window_set_child(GTK_WINDOW(window), area);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app =
            gtk_application_new("de.hwr_berlin.hwr_study_c", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}