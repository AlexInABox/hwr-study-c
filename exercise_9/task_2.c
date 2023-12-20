#include <gtk/gtk.h>

void print_hello() { printf("Hello GUI\n");
}
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app); // erstellt ein neues voll funktionsfähiges Fenster
    gtk_window_set_title(GTK_WINDOW(window), "hwr_study_c"); // Ändert den Namen des Fensters.
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200); // Setzt die Anfangsgröße des Fensters.
    GtkWidget *button = gtk_button_new_with_label("Hello GUI"); // Erstellt einen voll funktionsfähigen Button.
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL); // Übergibt eine Funktion, die ausgeführt wird, wenn der Button geklickt wird.
    gtk_window_set_child(GTK_WINDOW(window), button); // Fügt den Button als Kindelement zum Fenster hinzu.
    gtk_window_present(GTK_WINDOW(window)); // Lässt das Fenster anzeigen.
}
int main(int argc, char **argv) { GtkApplication *app =
            gtk_application_new("de.hwr_berlin.hwr_study_c", G_APPLICATION_DEFAULT_FLAGS); // Initialisiert eine neue GTK Applikation.
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL); // Übergibt eine Funktion, die aufgerufen werden kann, um ein neues Fenster zu bauen.
    int status = g_application_run(G_APPLICATION(app), argc, argv); // Führt die Applikation -> im Endeffekt die hinterlegte Funktion activate().
    g_object_unref(app); // Gibt alle benötigten Ressourcen wieder frei. Ähnlich zu free() und fclose().
    return status;
}