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
    liststore1 = Gtk.Template.Child()
    treeview = Gtk.Template.Child()
    label = Gtk.Template.Child()

    def __init__(self):
        super().__init__()
        # initialize phonedata by row (append)
        for phonedata in phonebook:
            self.liststore1.append(phonedata)

        # treeview is linked to listmodel
        # initialize treeview by column
        for i, column in enumerate(columns):
            # cellrenderer to render the text
            cell = Gtk.CellRendererText()
            # the text in the 0-th column should be in boldface
            if i == 0:
                cell.props.weight_set = True
                cell.props.weight = Pango.Weight.BOLD
            # column view is created from
            # i-th columns (= column) as header text and
            # i-th liststore1 data generating Gtk.CellRendererText()
            col = Gtk.TreeViewColumn(column, cell, text=i)
            # appended to the treeview by column
            self.treeview.append_column(col)

    @Gtk.Template.Callback()
    def onDestroy(self, *args):
        Gtk.main_quit()

    @Gtk.Template.Callback()
    def onChanged(self, selection):
        # get the model and the iterator that points at the data in the model
        (model, iter) = selection.get_selected()
        # set the label to a new value depending on the selection
        self.label.set_text("{} {} --> Phone: {}".format(model[iter][0],  model[iter][1], model[iter][2]))
        return True

window = SimpleWindow()
window.show()
Gtk.main()
