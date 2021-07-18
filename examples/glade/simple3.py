import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


@Gtk.Template(filename="simple3.ui")
class SimpleWindow(Gtk.Window):
    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "simple3"
    # corresponding name in XML 'id' attribute sets this class member variable
    label = Gtk.Template.Child()
    header = Gtk.Template.Child()
    header_label = Gtk.Template.Child()
    # class member variables
    entry_text = ""
    folder = ""

    @Gtk.Template.Callback()
    def onDestroy(self, *args):
        Gtk.main_quit()

    @Gtk.Template.Callback()
    def onFileChooserButtonChanged(self, widget):
        self.folder = widget.get_filename()

    @Gtk.Template.Callback()
    def onButtonPressed(self, widget):
        print("=" * 80)
        print("Button label:    " + widget.get_label())
        print("Entered text:    " + self.entry_text)
        print("Folder      :    " + self.folder)
        # This is right, I think.
        self.label.set_label(self.entry_text.upper())
        self.header_label.set_label(self.entry_text.lower())

    @Gtk.Template.Callback()
    def onEntryChanged(self, widget):
        self.entry_text = widget.get_text()


window = SimpleWindow()

#window.header.props.title = "Convert2Html"
window.set_titlebar(window.header)
window.show()

Gtk.main()
