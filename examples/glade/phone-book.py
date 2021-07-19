import gi

gi.require_version("Gtk", "3.0")
from gi.repository import Gtk
from gi.repository import Pango
import sys

# columns are not in XML so only these are used
columns = ["First Name",
           "Last Name",
           "Phone Number"]

# data are in XML so this goes after existing ones
phonebook = [["Jurg", "Billeter", "555-0123"],
             ["Johannes", "Schmid", "555-1234"],
             ["Julita", "Inca", "555-2345"],
             ["Javier", "Jardon", "555-3456"],
             ["Jason", "Clinton", "555-4567"],
             ["Random J.", "Hacker", "555-5678"]]

@Gtk.Template(filename="phone-book.ui")
class SimpleWindow(Gtk.Window):

    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "phone_book"
    # corresponding name in XML 'id' attribute sets this class member variable
    liststore1 = Gtk.Template.Child() # MODEL
    treeview = Gtk.Template.Child()   # VIEW
    label = Gtk.Template.Child()

    def __init__(self):
        super().__init__()
        # initialize MODEL by row (append)
        for phonedata in phonebook:
            self.liststore1.append(phonedata)

        # treeview VIEW is linked to liststore1 MODEL
        # treeview VIEW lacks renderer
        for i, column in enumerate(columns):
            renderer_text = Gtk.CellRendererText()
            # 0-th column in MODEL should be in boldface
            if i == 0:
                renderer_text.props.weight_set = True
                renderer_text.props.weight = Pango.Weight.BOLD
            # create a view_col for i-th column in MODEL
            view_col = Gtk.TreeViewColumn(title=column, cell_renderer=renderer_text, text=i)
            # append view_col to VIEW
            self.treeview.append_column(view_col)

    @Gtk.Template.Callback()
    def onDestroy(self, *args):
        Gtk.main_quit()

    @Gtk.Template.Callback()
    def onChanged(self, selection):
        # get MODEL and the iterator that points at the data in MODEL
        (model, iter) = selection.get_selected()
        # set the label to a new value depending on the selection
        self.label.set_text("{} {} --> Phone: {}".format(model[iter][0],  model[iter][1], model[iter][2]))
        return True

window = SimpleWindow()
window.show()
Gtk.main()
