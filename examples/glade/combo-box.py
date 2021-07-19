import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

@Gtk.Template(filename="combo-box.ui")
class SimpleWindow(Gtk.Window):

    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "combo_boxes"
    # corresponding name in XML 'id' attribute sets this class member variable
    liststore_country = Gtk.Template.Child() # MODEL
    liststore_lang1 = Gtk.Template.Child()   # MODEL
    combo_country = Gtk.Template.Child()     # VIEW
    combo_lang1 = Gtk.Template.Child()       # VIEW
    button = Gtk.Template.Child()

    def __init__(self):
        super().__init__()

        renderer_text = Gtk.CellRendererText()
        # pack_start(cell, expand), Here, cell (Gtk.CellRenderer) 
        self.combo_country.pack_start(renderer_text, True)
        # add_attribute (cell, attribute, column)
        self.combo_country.add_attribute(renderer_text, "text", 0)

        tree_iter = self.combo_country.get_active_iter()
        self.country = self.liststore_country[tree_iter][0]

        self.combo_lang1.pack_start(renderer_text, True)
        self.combo_lang1.add_attribute(renderer_text, "text", 0)

        tree_iter = self.combo_lang1.get_active_iter()
        self.lang1 = self.liststore_lang1[tree_iter][0]

    @Gtk.Template.Callback()
    def onDestroy(self, *args):
        Gtk.main_quit()

    @Gtk.Template.Callback()
    def onCountryChanged(self, widget):
        tree_iter = widget.get_active_iter()
        model = widget.get_model()
        country = model[tree_iter][0]
        print("Selected: country = '{}'".format(country))
        self.country = country

    @Gtk.Template.Callback()
    def onLang1Changed(self, widget):
        tree_iter = widget.get_active_iter()
        model = widget.get_model()
        lang1 = model[tree_iter][0]
        print("Selected:                    lang1 = '{}'".format(lang1))
        self.lang1 = lang1

    @Gtk.Template.Callback()
    def onButtonPressed(self, widget):
        print("=" * 80)
        print("country = '{}', lang1 = '{}'".format(self.country, self.lang1))
        print("~" * 80)

window = SimpleWindow()
window.show()
Gtk.main()
