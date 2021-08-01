#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

static void
hello(GtkWidget* button, gpointer self);

static void
quit(GtkWidget* button, gpointer self);

static int i;

static void
hello(GtkWidget* button, gpointer self) {
    i ++;
    gtk_button_set_label(GTK_BUTTON(button), 
        g_strdup_printf("Hello, World!\nClick count = %i", i));
}

static void
quit(GtkWidget* button, gpointer self) {
    gtk_main_quit ();
}

int
main(int argc, char ** args) {
    GtkWidget* window;
    GtkWidget* button;

    i = 0;
    g_type_init();
    gtk_init(&argc, &args);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "My first GUI program");
    gtk_container_set_border_width(GTK_CONTAINER(window), (guint) 10);
    g_object_set(GTK_WINDOW(window), "window-position",
        GTK_WIN_POS_CENTER, NULL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 100);
    g_signal_connect(window, "destroy", G_CALLBACK(quit), NULL);
    button = gtk_button_new_with_label("Click me!");
    g_signal_connect_data(button, "clicked", G_CALLBACK(hello), NULL, NULL, 0);
    gtk_container_add(GTK_CONTAINER(window), button);
    gtk_widget_show_all(window);
    gtk_main();
    return EXIT_SUCCESS;
}

