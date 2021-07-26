import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


@Gtk.Template(filename="head_win.ui")
class Window(Gtk.Window):
    __gtype_name__ = "window"

    entry = Gtk.Template.Child()
    label = Gtk.Template.Child()

    def __init__(self):
        super().__init__()
        self.entry_text = ""

    @Gtk.Template.Callback("on_window_destroy")
    def onDestroy(self, widget):
        Gtk.main_quit()

    @Gtk.Template.Callback("on_button_clicked")
    def onButton(self, widget):
        self.label.set_label("*** " + self.entry_text + " ***")

    @Gtk.Template.Callback("on_entry_activate")
    def onEntry(self, widget):
        self.entry_text = self.entry.get_text()
        self.label.set_label(self.entry.get_text())
        widget.set_text("")

    @Gtk.Template.Callback("on_go_prev_clicked")
    def onGoPrev(self, widget):
        print("Dummy: onGoPrev")

    @Gtk.Template.Callback("on_go_next_clicked")
    def onGoNext(self, widget):
        print("Dummy: onGoNext")

    @Gtk.Template.Callback("on_configure_clicked")
    def onConfigure(self, widget):
        print("Dummy: onConfigure")

    @Gtk.Template.Callback("on_menu1_clicked")
    def onFile(self, widget):
        print("Dummy: onFile")

    @Gtk.Template.Callback("on_menu2_clicked")
    def onEdit(self, widget):
        print("Dummy: onEdit")

    @Gtk.Template.Callback("on_menu3_clicked")
    def onPreference(self, widget):
        print("Dummy: onPreference")

    @Gtk.Template.Callback("on_menu4_clicked")
    def onHelp(self, widget):
        print("Dummy: onHelp")

    @Gtk.Template.Callback("on_menu5_clicked")
    def onAbout(self, widget):
        self.set_title(self.entry_text)


window = Window()
window.set_title("Demo HeaderBar")
window.show_all()
Gtk.main()
