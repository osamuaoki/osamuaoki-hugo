/* gui-3.c generated by valac 0.20.1, the Vala compiler
 * generated from gui-3.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_GUI (gui_get_type ())
#define GUI(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GUI, Gui))
#define GUI_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_GUI, GuiClass))
#define IS_GUI(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GUI))
#define IS_GUI_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_GUI))
#define GUI_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_GUI, GuiClass))

typedef struct _Gui Gui;
typedef struct _GuiClass GuiClass;
typedef struct _GuiPrivate GuiPrivate;
typedef struct _Block1Data Block1Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _Gui {
	GtkWindow parent_instance;
	GuiPrivate * priv;
};

struct _GuiClass {
	GtkWindowClass parent_class;
};

struct _GuiPrivate {
	gint i;
};

struct _Block1Data {
	int _ref_count_;
	Gui * self;
	GtkButton* button;
};


static gpointer gui_parent_class = NULL;

GType gui_get_type (void) G_GNUC_CONST;
#define GUI_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_GUI, GuiPrivate))
enum  {
	GUI_DUMMY_PROPERTY
};
static gint gui_run (Gui* self);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self);
static void __lambda2_ (Block1Data* _data1_);
static void ___lambda2__gtk_button_clicked (GtkButton* _sender, gpointer self);
gint gui_main (gchar** args, int args_length1);
Gui* gui_new (void);
Gui* gui_construct (GType object_type);
static void gui_finalize (GObject* obj);


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		Gui * self;
		self = _data1_->self;
		_g_object_unref0 (_data1_->button);
		_g_object_unref0 (self);
		g_slice_free (Block1Data, _data1_);
	}
}


static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self) {
	gtk_main_quit ();
}


static void __lambda2_ (Block1Data* _data1_) {
	Gui * self;
	gint _tmp0_;
	gint _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_;
	self = _data1_->self;
	_tmp0_ = self->priv->i;
	self->priv->i = _tmp0_ + 1;
	_tmp1_ = self->priv->i;
	_tmp2_ = g_strdup_printf ("Hello, World!\nClick count = %i", _tmp1_);
	_tmp3_ = _tmp2_;
	gtk_button_set_label (_data1_->button, _tmp3_);
	_g_free0 (_tmp3_);
}


static void ___lambda2__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda2_ (self);
}


static gint gui_run (Gui* self) {
	gint result = 0;
	Block1Data* _data1_;
	GtkButton* _tmp0_;
	g_return_val_if_fail (self != NULL, 0);
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_data1_->self = g_object_ref (self);
	gtk_window_set_title ((GtkWindow*) self, "My first GUI program");
	gtk_container_set_border_width ((GtkContainer*) self, (guint) 10);
	g_object_set ((GtkWindow*) self, "window-position", GTK_WIN_POS_CENTER, NULL);
	gtk_window_set_default_size ((GtkWindow*) self, 400, 100);
	g_signal_connect ((GtkWidget*) self, "destroy", (GCallback) _gtk_main_quit_gtk_widget_destroy, NULL);
	self->priv->i = 0;
	_tmp0_ = (GtkButton*) gtk_button_new_with_label ("Click me!");
	g_object_ref_sink (_tmp0_);
	_data1_->button = _tmp0_;
	g_signal_connect_data (_data1_->button, "clicked", (GCallback) ___lambda2__gtk_button_clicked, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _data1_->button);
	gtk_widget_show_all ((GtkWidget*) self);
	result = 0;
	block1_data_unref (_data1_);
	_data1_ = NULL;
	return result;
}


gint gui_main (gchar** args, int args_length1) {
	gint result = 0;
	Gui* _tmp0_;
	Gui* window;
	gtk_init (&args_length1, &args);
	_tmp0_ = gui_new ();
	g_object_ref_sink (_tmp0_);
	window = _tmp0_;
	gui_run (window);
	gtk_main ();
	result = 0;
	_g_object_unref0 (window);
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return gui_main (argv, argc);
}


Gui* gui_construct (GType object_type) {
	Gui * self = NULL;
	self = (Gui*) g_object_new (object_type, NULL);
	return self;
}


Gui* gui_new (void) {
	return gui_construct (TYPE_GUI);
}


static void gui_class_init (GuiClass * klass) {
	gui_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (GuiPrivate));
	G_OBJECT_CLASS (klass)->finalize = gui_finalize;
}


static void gui_instance_init (Gui * self) {
	self->priv = GUI_GET_PRIVATE (self);
}


static void gui_finalize (GObject* obj) {
	Gui * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_GUI, Gui);
	G_OBJECT_CLASS (gui_parent_class)->finalize (obj);
}


GType gui_get_type (void) {
	static volatile gsize gui_type_id__volatile = 0;
	if (g_once_init_enter (&gui_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GuiClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gui_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Gui), 0, (GInstanceInitFunc) gui_instance_init, NULL };
		GType gui_type_id;
		gui_type_id = g_type_register_static (GTK_TYPE_WINDOW, "Gui", &g_define_type_info, 0);
		g_once_init_leave (&gui_type_id__volatile, gui_type_id);
	}
	return gui_type_id__volatile;
}


