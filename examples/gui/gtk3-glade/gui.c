#include <gtk/gtk.h>

static int i;

static void 
on_window1_destroy (GtkWidget *object, gpointer user_data)
{
    gtk_main_quit ();
}

static void
hello(GtkWidget* button, gpointer self) {
    i ++;
    gtk_button_set_label(GTK_BUTTON(button), 
        g_strdup_printf("Hello, World!\nClick count = %i", i));
}

int
main (int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;
    GtkWidget       *button;

    gtk_init (&argc, &argv);
    i = 0;
    builder = gtk_builder_new ();
    gtk_builder_add_from_file (builder, "clickme.glade", NULL);
    window = GTK_WIDGET (gtk_builder_get_object (builder, "window1"));
    g_signal_connect (window, "destroy", (GCallback) on_window1_destroy, NULL);
    button = GTK_WIDGET (gtk_builder_get_object (builder, "button1"));
    g_signal_connect (button, "clicked", (GCallback) hello, NULL);
    g_object_unref (G_OBJECT (builder));
        
    gtk_widget_show (window);                
    gtk_main ();

    return EXIT_SUCCESS;
}
