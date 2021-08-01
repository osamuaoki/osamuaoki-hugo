using Gtk;

class HelloWorld : Object {

    private static int i;

    public static void on_button1_clicked (Button button) {
        i += 1;
        button.label = "Hello, World!\nClick count = %i".printf(i);
    }

    public static void on_window1_destroy (Window window) {
        Gtk.main_quit ();
    }

    public int run (string[] args) {     
        i = 0;
        try {
            var builder = new Builder ();
            builder.add_from_file ("clickme-ext.glade");
            var window = builder.get_object ("window1") as Window;
            builder.connect_signals (builder);
            window.show_all ();
        } catch (Error e) {
            stderr.printf ("Could not load UI: %s\n", e.message);
            return 1;
        } 
        return 0;
    }
}
int main (string[] args) {     
    Gtk.init (ref args);
    var h = new HelloWorld();
    h.run(args);
    Gtk.main ();
    return 0;
}

