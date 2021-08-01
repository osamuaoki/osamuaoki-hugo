using Gtk;

int main (string[] args) {
    Gtk.init (ref args);
    int i;

    var window = new Window ();
    window.title = "My first GUI program";
    window.border_width = 10;
    window.window_position = WindowPosition.CENTER;
    window.set_default_size (400, 100);
    window.destroy.connect (Gtk.main_quit);

    i = 0;
    var button = new Button.with_label ("Click me!");
    button.clicked.connect (() => {
        i ++;
        button.label = "Hello, World!\nClick count = %i".printf(i);
        });

    window.add (button);
    window.show_all ();

    Gtk.main ();
    return 0;
}
