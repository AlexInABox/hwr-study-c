#include <gtk/gtk.h>

void draw_function(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer data) {

    double red = 255.0;
    double green = 0.0;
    double blue = 0.0;
    // 6 iterations

    for (int i = 1; i <= 255; i++){
        cairo_set_source_rgb(cr, red / 255.0, green / 255.0, blue / 255.0);
        cairo_move_to(cr, width * (i / (255.0*6)), height * 0);
        cairo_line_to(cr, width * (i / (255.0*6)), height * 1);
        cairo_set_line_width(cr, 1);
        cairo_stroke(cr);
        green++;
    }
    for (int i = 255; i <= 255*2; i++){
        cairo_set_source_rgb(cr, red / 255.0, green / 255.0, blue / 255.0);
        cairo_move_to(cr, width * (i / (255.0*6)), height * 0);
        cairo_line_to(cr, width * (i / (255.0*6)), height * 1);
        cairo_set_line_width(cr, 1);
        cairo_stroke(cr);
        red--;
    }
    for (int i = 255*2; i <= 255*3; i++){
        cairo_set_source_rgb(cr, red / 255.0, green / 255.0, blue / 255.0);
        cairo_move_to(cr, width * (i / (255.0*6)), height * 0);
        cairo_line_to(cr, width * (i / (255.0*6)), height * 1);
        cairo_set_line_width(cr, 1);
        cairo_stroke(cr);
        blue++;
    }
    for (int i = 255*3; i <= 255*4; i++){
        cairo_set_source_rgb(cr, red / 255.0, green / 255.0, blue / 255.0);
        cairo_move_to(cr, width * (i / (255.0*6)), height * 0);
        cairo_line_to(cr, width * (i / (255.0*6)), height * 1);
        cairo_set_line_width(cr, 1);
        cairo_stroke(cr);
        green--;
    }
    for (int i = 255*4; i <= 255*5; i++){
        cairo_set_source_rgb(cr, red / 255.0, green / 255.0, blue / 255.0);
        cairo_move_to(cr, width * (i / (255.0*6)), height * 0);
        cairo_line_to(cr, width * (i / (255.0*6)), height * 1);
        cairo_set_line_width(cr, 1);
        cairo_stroke(cr);
        red++;
    }
    for (int i = 255*5; i <= 255*6; i++){
        cairo_set_source_rgb(cr, red / 255.0, green / 255.0, blue / 255.0);
        cairo_move_to(cr, width * (i / (255.0*6)), height * 0);
        cairo_line_to(cr, width * (i / (255.0*6)), height * 1);
        cairo_set_line_width(cr, 1);
        cairo_stroke(cr);
        blue--;
    }
}

void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "E9T6");
    gtk_window_set_default_size(GTK_WINDOW(window), 255, 255);
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