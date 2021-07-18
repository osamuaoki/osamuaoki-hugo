import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk


@Gtk.Template(filename="simple2.ui")
class SimpleWindow(Gtk.Window):
    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "simple2"
    # corresponding name in XML 'id' attribute sets this class member variable
    label = Gtk.Template.Child()
    # class member variables
    entry_text = "(null as init)"
    spin1_text = "0 (init)"
    spin2_text = "0 (init)"
    toggle1_text = "___ off ___ (init)"
    toggle2_text = "___ off ___ (init)"
    check1_text = "___ off ___ (init)"
    check2_text = "___ off ___ (init)"
    radio_text = "radiobutton1 (init)"
    folder = "(null as init)"

    @Gtk.Template.Callback()
    def onDestroy(self, *args):
        Gtk.main_quit()

    @Gtk.Template.Callback()
    def onButtonPressed(self, widget):
        print("=" * 80)
        print("Button label:    " + widget.get_label())
        print("Entered text:    " + self.entry_text)
        print("Spin1 value :    " + self.spin1_text)
        print("Spin2 value :    " + self.spin2_text)
        print("Toggle1 text:    " + self.toggle1_text)
        print("Toggle2 text:    " + self.toggle2_text)
        print("Check1 text :    " + self.check1_text)
        print("Check2 text :    " + self.check2_text)
        print("Radio text  :    " + self.radio_text)
        print("Folder      :    " + self.folder)
        # This is right, I think.
        self.label.set_label(self.entry_text)

    @Gtk.Template.Callback()
    def onEntryChanged(self, widget):
        self.entry_text = widget.get_text()

    @Gtk.Template.Callback()
    def onSpinButton1Changed(self, widget):
        self.spin1_text = str(widget.get_value_as_int())

    @Gtk.Template.Callback()
    def onSpinButton2Changed(self, widget):
        self.spin2_text = str(widget.get_value_as_int())

    @Gtk.Template.Callback()
    def onToggleButton1Toggled(self, widget):
        if widget.get_active():
            self.toggle1_text = "@@@ ON  @@@"
        else:
            self.toggle1_text = "___ off ___"

    @Gtk.Template.Callback()
    def onToggleButton2Toggled(self, widget):
        if widget.get_active():
            self.toggle2_text = "@@@ ON  @@@"
        else:
            self.toggle2_text = "___ off ___"

    @Gtk.Template.Callback()
    def onCheckButton1Toggled(self, widget):
        if widget.get_active():
            self.check1_text = "@@@ ON  @@@"
        else:
            self.check1_text = "___ off ___"

    @Gtk.Template.Callback()
    def onCheckButton2Toggled(self, widget):
        if widget.get_active():
            self.check2_text = "@@@ ON  @@@"
        else:
            self.check2_text = "___ off ___"

    @Gtk.Template.Callback()
    def onRadioButtonToggled(self, widget):
        if widget.get_active():
            self.radio_text = widget.get_label()

    @Gtk.Template.Callback()
    def onFileChooserButtonSet(self, widget):
        self.folder = widget.get_filename()

window = SimpleWindow()
window.show()

Gtk.main()
