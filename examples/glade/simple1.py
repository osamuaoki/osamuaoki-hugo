import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


@Gtk.Template(filename="simple1.ui")
class SimpleWindow(Gtk.Window):
    # corresponding class in XML
    __gtype_name__ = "Simple1"
    # class variable and corresponding widget in XML
    label = Gtk.Template.Child("Label")
    entry_text = ""

    @Gtk.Template.Callback()
    def onDestroy(self, *args):
        Gtk.main_quit()

    @Gtk.Template.Callback()
    def onButtonPressed(self, widget):
        print("=" * 80)
        print("Button label:    " + widget.get_label())
        print("Entered text:    " + self.entry_text)
        # This is right, I think.
        self.label.set_label(self.entry_text)

    @Gtk.Template.Callback()
    def onEntryChanged(self, widget):
        self.entry_text = widget.get_text()


window = SimpleWindow()
window.show()

Gtk.main()
