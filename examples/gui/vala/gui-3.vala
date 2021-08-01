using Gtk;

class Gui : Gtk.Window {

    private int i;

    private int run() {
        this.title = "My first GUI program";
        this.border_width = 10;
        this.window_position = WindowPosition.CENTER;
        this.set_default_size (400, 100);
        this.destroy.connect (Gtk.main_quit);
    
        this.i = 0;
        var button = new Button.with_label ("Click me!");
        button.clicked.connect (() => {
            this.i ++;
            button.label = "Hello, World!\nClick count = %i".printf(this.i);
            });
    
        this.add (button);
    	this.show_all ();
	return 0;
    }

    public static int main (string[] args) {
        Gtk.init (ref args);
    
        var window = new Gui ();
        window.run();
        Gtk.main ();
        return 0;
    }
}
