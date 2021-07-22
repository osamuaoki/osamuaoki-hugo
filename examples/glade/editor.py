import gi

gi.require_version("Gtk", "3.0")
gi.require_version('GtkSource', '3.0')
from gi.repository import Gtk, Pango, GtkSource


@Gtk.Template(filename="editor-main.ui")
class TextViewWindow(Gtk.Window):
    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "main"
    # corresponding name in XML 'id' attribute sets this class member variable
    editable = Gtk.Template.Child()
    invisible = Gtk.Template.Child()
    mono = Gtk.Template.Child()
    one = Gtk.Template.Child()
    char = Gtk.Template.Child()
    word = Gtk.Template.Child()
    left = Gtk.Template.Child()
    center = Gtk.Template.Child()
    right = Gtk.Template.Child()
    fill = Gtk.Template.Child()
    scrollwin = Gtk.Template.Child()

    def __init__(self):
        super().__init__()
        #################################################################################
        # Let's add widgets and buffer not supported by Glade
        # (replacing GtkTextView and GtkTextBuffer)
        #    s/text/source/ later
        #################################################################################
        self.textview = GtkSource.View()
        self.textbuffer = self.textview.get_buffer()
        self.textbuffer.set_text(
            "This is some text inside of a Gtk.SourceView. "
            + "Select text and click one of the buttons 'bold', 'italic', "
            + "or 'underline' to modify the text accordingly.\n\n"
            + "	• This search can be one with case insensitive match.\n"
            + "	• This search can be one with regular expression match.\n\n"
            + "日本国民は、正当に選挙された国会における代表者を通じて行動し、"
            + "われらとわれらの子孫のために、諸国民との協和による成果と、"
            + "わが国全土にわたつて自由のもたらす恵沢を確保し、"
            + "政府の行為によつて再び戦争の惨禍が起ることのないやうにすることを決意し、"
            + "ここに主権が国民に存することを宣言し、この憲法を確定する。"
            + "そもそも国政は、国民の厳粛な信託によるものであつて、その権威は国民に由来し、"
            + "その権力は国民の代表者がこれを行使し、その福利は国民がこれを享受する。"
            + "これは人類普遍の原理であり、この憲法は、かかる原理に基くものである。"
            + "われらは、これに反する一切の憲法、法令及び詔勅を排除する。\n\n"
            + "日本国民は、恒久の平和を念願し、人間相互の関係を支配する崇高な理想を深く自覚するのであつて、"
            + "平和を愛する諸国民の公正と信義に信頼して、われらの安全と生存を保持しようと決意した。"
            + "われらは、平和を維持し、専制と隷従、圧迫と偏狭を地上から永遠に除去しようと努めてゐる国際社会において、"
            + "名誉ある地位を占めたいと思ふ。われらは、全世界の国民が、"
            + "ひとしく恐怖と欠乏から免かれ、平和のうちに生存する権利を有することを確認する。\n\n"
            + "われらは、いづれの国家も、自国のことのみに専念して他国を無視してはならないのであつて、"
            + "政治道徳の法則は、普遍的なものであり、この法則に従ふことは、自国の主権を維持し、"
            + "他国と対等関係に立たうとする各国の責務であると信ずる。\n\n"
            + "日本国民は、国家の名誉にかけ、全力をあげてこの崇高な理想と目的を達成することを誓ふ。\n\n"
            + "« L'Assemblée nationale décrète qu'elle borne quant à présent la Déclaration des droits "
            + "de l'homme et du citoyen aux dix-sept articles qu'elle a arrêtés, et qu'elle va procéder "
            + "sans délai à fixer la Constitution de la France pour assurer la prospérité publique, sauf "
            + "à ajouter après le travail de la Constitution les articles qu'elle croirait nécessaires "
            + "pour compléter la Déclaration des droits. »"
        )
        self.scrollwin.add(self.textview)
        #################################################################################
        self.tag_bold = self.textbuffer.create_tag("bold", weight=Pango.Weight.BOLD)
        self.tag_italic = self.textbuffer.create_tag("italic", style=Pango.Style.ITALIC)
        self.tag_under = self.textbuffer.create_tag(
            "underline", underline=Pango.Underline.SINGLE
        )
        self.tag_found = self.textbuffer.create_tag("found", background="yellow")
        # check Glade XML initial settings and set them so
        if self.editable.get_active():
            self.editable = self.editable.get_active()
            self.textview.set_editable(self.editable)
        if self.invisible.get_active():
            self.invisible = self.invisible.get_active()
            self.textview.set_visible(not self.invisible)
        if self.mono.get_active():
            self.mono = self.mono.get_active()
            self.textview.set_monospace(self.mono)
        if self.one.get_active():
            self.textview.set_wrap_mode(Gtk.WrapMode.NONE)
        if self.char.get_active():
            self.textview.set_wrap_mode(Gtk.WrapMode.CHAR)
        if self.word.get_active():
            self.textview.set_wrap_mode(Gtk.WrapMode.WORD)
        if self.left.get_active():
            self.textview.set_justification(Gtk.Justification.LEFT)
        if self.center.get_active():
            self.textview.set_justification(Gtk.Justification.CENTER)
        if self.right.get_active():
            self.textview.set_justification(Gtk.Justification.RIGHT)
        if self.fill.get_active():
            self.textview.set_justification(Gtk.Justification.FILL)

    # common function for callbacks
    def button_apply_tag(self, tag):
        bounds = self.textbuffer.get_selection_bounds()
        if len(bounds) != 0 and self.editable:
            start, end = bounds
            self.textbuffer.apply_tag(tag, start, end)

    @Gtk.Template.Callback()
    def on_bold_clicked(self, widget):
        self.button_apply_tag(self.tag_bold)

    @Gtk.Template.Callback()
    def on_italic_clicked(self, widget):
        self.button_apply_tag(self.tag_italic)

    @Gtk.Template.Callback()
    def on_under_clicked(self, widget):
        self.button_apply_tag(self.tag_under)

    @Gtk.Template.Callback()
    def on_clear_clicked(self, widget):
        start = self.textbuffer.get_start_iter()
        end = self.textbuffer.get_end_iter()
        self.textbuffer.remove_all_tags(start, end)

    @Gtk.Template.Callback()
    def on_editable_toggled(self, widget):
        self.editable = widget.get_active()
        self.textview.set_editable(self.editable)

    @Gtk.Template.Callback()
    def on_invisible_toggled(self, widget):
        self.invisible = widget.get_active()
        self.textview.set_cursor_visible(not self.invisible)

    @Gtk.Template.Callback()
    def on_mono_toggled(self, widget):
        self.mono = widget.get_active()
        self.textview.set_monospace(self.mono)

    @Gtk.Template.Callback()
    def on_one_toggled(self, widget):
        if widget.get_active():
            self.textview.set_wrap_mode(Gtk.WrapMode.NONE)

    @Gtk.Template.Callback()
    def on_char_toggled(self, widget):
        if widget.get_active():
            self.textview.set_wrap_mode(Gtk.WrapMode.CHAR)

    @Gtk.Template.Callback()
    def on_word_toggled(self, widget):
        if widget.get_active():
            self.textview.set_wrap_mode(Gtk.WrapMode.WORD)

    @Gtk.Template.Callback()
    def on_left_toggled(self, widget):
        if widget.get_active():
            self.textview.set_justification(Gtk.Justification.LEFT)

    @Gtk.Template.Callback()
    def on_center_toggled(self, widget):
        if widget.get_active():
            self.textview.set_justification(Gtk.Justification.CENTER)

    @Gtk.Template.Callback()
    def on_right_toggled(self, widget):
        if widget.get_active():
            self.textview.set_justification(Gtk.Justification.RIGHT)

    @Gtk.Template.Callback()
    def on_fill_toggled(self, widget):
        if widget.get_active():
            self.textview.set_justification(Gtk.Justification.FILL)

    @Gtk.Template.Callback()
    def on_search_clicked(self, widget):
        dialog = SearchDialog(self)
        dialog.set_transient_for(self)
        dialog.set_modal(True)
        dialog.show_all()
        # ==== This is important part for *dialog =====
        # Clicking button placed in the particular *dialog makes dialog to
        # exit the event loop while emitting a response signal if the
        # Response ID entry in Glade is activated.
        response = dialog.run()
        search_settings = GtkSource.SearchSettings()
        search_settings.set_case_sensitive(dialog.case_sensitive)
        search_settings.set_regex_enabled(dialog.regex_enabled)
        search_settings.set_search_text(dialog.searchbox.get_text())
        # buffer (GtkSource.Buffer) – a GtkSource.Buffer.
        # settings (GtkSource.SearchSettings or None) – a GtkSource.SearchSettings, or None.
        self.search_context = GtkSource.SearchContext(buffer=self.textbuffer, settings=search_settings)
        if response == Gtk.ResponseType.OK:
            cursor_mark = self.textbuffer.get_insert()
            start = self.textbuffer.get_iter_at_mark(cursor_mark)
            if start.get_offset() == self.textbuffer.get_char_count():
                start = self.textbuffer.get_start_iter()
            self.search_and_mark(start)
        dialog.destroy()

    def search_and_mark(self, start):
        end = self.textbuffer.get_end_iter()
        flag, match_start, match_end, has_wrapped_around = self.search_context.forward2(start)
        if flag:
            self.textbuffer.apply_tag(self.tag_found, match_start, match_end)
            self.search_and_mark(match_end)


@Gtk.Template(filename="editor-search.ui")
class SearchDialog(Gtk.Dialog):
    # corresponding name in XML 'class' attribute for this class
    __gtype_name__ = "search_win"
    # corresponding name in XML 'id' attribute sets this class member variable
    find = Gtk.Template.Child()
    cancel = Gtk.Template.Child()
    label = Gtk.Template.Child()
    searchbox = Gtk.Template.Child()
    nocase = Gtk.Template.Child()
    regex = Gtk.Template.Child()

    def __init__(self, parent):
        super().__init__()
        # initialize from Glade XML settings
        if self.nocase.get_active():
            self.case_sensitive = False
        else:
            self.case_sensitive = True
        if self.regex.get_active():
            self.regex_enabled = False
        else:
            self.regex_enabled = True

    @Gtk.Template.Callback()
    def on_cancel_clicked(self, widget):
        print("I: cancel clicked")

    @Gtk.Template.Callback()
    def on_searchbox_search_changed(self, widget):
        pass

    @Gtk.Template.Callback()
    def on_regex_toggled(self, widget):
        if widget.get_active():
            self.regex_enabled = True
        else:
            self.regex_enabled = False

    @Gtk.Template.Callback()
    def on_nocase_toggled(self, widget):
        if widget.get_active():
            self.case_sensitive = False
        else:
            self.case_sensitive = True


win = TextViewWindow()
win.connect("destroy", Gtk.main_quit)
win.show_all()
Gtk.main()
