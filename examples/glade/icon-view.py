import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk
from gi.repository.GdkPixbuf import Pixbuf

@Gtk.Template(filename="icon-view.ui")
class SimpleWindow(Gtk.Window):

    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "icon-views"
    # corresponding name in XML 'id' attribute sets this class member variable
    liststore1 = Gtk.Template.Child() # MODEL
    iconview = Gtk.Template.Child()   # VIEW
    button = Gtk.Template.Child()

    def __init__(self):
        super().__init__()
        renderer_pixbuf = Gtk.CellRendererPixbuf()
        self.iconview.pack_start(renderer_pixbuf, True)
        self.iconview.add_attribute(renderer_pixbuf, "pixbuf", 0)
        renderer_text = Gtk.CellRendererText()
        self.iconview.pack_start(renderer_text, True)
        self.iconview.add_attribute(renderer_text, "text", 1)

    @Gtk.Template.Callback()
    def onDestroy(self, *args):
        Gtk.main_quit()

    @Gtk.Template.Callback()
    def onButtonPressed(self, widget):
        print("=" * 80)

window = SimpleWindow()
window.show_all()
Gtk.main()
