#include <gtk/gtk.h>

int increment = 0;
GtkWidget *button1;

void print_hello() {
    increment++;
    char number[25];
    sprintf(number, "%s%d", "Inkrementiere: ", increment);
    gtk_button_set_label((GtkButton *) button1, number);
}

void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "E9T4");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    GtkWidget *grid = gtk_grid_new(); // Erstellt ein Element, dass ein Gridsystem enthält, um mehrere Elemente strukturiert anzuordnen.

    // Das Gridsystem besteht aus Zellen, dessen Start in der Ecke links oben ist.
    gtk_window_set_child(GTK_WINDOW(window), grid); // Fügt das Gridsystem als Kindelement des Fensters hinzu.
    button1 = gtk_button_new_with_label("Inkrementiere: 0");
    g_signal_connect(button1, "clicked", G_CALLBACK(print_hello), NULL);

    gtk_grid_attach(GTK_GRID (grid), button1, 0, 0, 1,1); // Fügt den Button in der Gridzelle (0, 0) hinzu und soll nur eine Gridzelle ausfüllen.
    GtkWidget *quitButton = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped (quitButton, "clicked", G_CALLBACK(gtk_window_destroy),
                              window); // gtk_window_destroy sendet ein Signal an das Fenster, dass es geschlossen werden soll.
    gtk_grid_attach(GTK_GRID (grid), quitButton, 0, 1, 4,
                    1); // Fügt den Button in der Gridzelle (0, 1) hinzu und soll zwei Gridzellen auf der horizontalen Ebene ausfüllen.
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