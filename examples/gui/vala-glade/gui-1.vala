using Gtk;

int i;

public void on_button1_clicked (Button button) {
    i += 1;
    button.label = "Hello, World!\nClick count = %i".printf(i);
}

public void on_window1_destroy (Window window) {
    Gtk.main_quit ();
}

int main (string[] args) {     
    Gtk.init (ref args);
    i = 0;
    try {
        var builder = new Builder ();
        builder.add_from_file ("clickme.glade");
        builder.connect_signals (null);
        var window = builder.get_object ("window1") as Window;
        window.show_all ();
    } catch (Error e) {
        stderr.printf ("Could not load UI: %s\n", e.message);
        return 1;
    } 
    Gtk.main ();
    return 0;
}
