import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


@Gtk.Template(filename="simple1.ui")
class SimpleWindow(Gtk.Window):
    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "simple1"
    # corresponding name in XML 'id' attribute sets this class member variable
    label = Gtk.Template.Child()
    # class member variable
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
