/* gui-1.c generated by valac 0.20.1, the Vala compiler
 * generated from gui-1.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct _Block1Data Block1Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _Block1Data {
	int _ref_count_;
	gint i;
	GtkButton* button;
};



gint _vala_main (gchar** args, int args_length1);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self);
static void __lambda2_ (Block1Data* _data1_);
static void ___lambda2__gtk_button_clicked (GtkButton* _sender, gpointer self);


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_object_unref0 (_data1_->button);
		g_slice_free (Block1Data, _data1_);
	}
}


static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self) {
	gtk_main_quit ();
}


static void __lambda2_ (Block1Data* _data1_) {
	gint _tmp0_;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	_tmp0_ = _data1_->i;
	_data1_->i = _tmp0_ + 1;
	_tmp1_ = g_strdup_printf ("Hello, World!\nClick count = %i", _data1_->i);
	_tmp2_ = _tmp1_;
	gtk_button_set_label (_data1_->button, _tmp2_);
	_g_free0 (_tmp2_);
}


static void ___lambda2__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda2_ (self);
}


gint _vala_main (gchar** args, int args_length1) {
	gint result = 0;
	Block1Data* _data1_;
	GtkWindow* _tmp0_;
	GtkWindow* window;
	GtkButton* _tmp1_;
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	gtk_init (&args_length1, &args);
	_tmp0_ = (GtkWindow*) gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_object_ref_sink (_tmp0_);
	window = _tmp0_;
	gtk_window_set_title (window, "My first GUI program");
	gtk_container_set_border_width ((GtkContainer*) window, (guint) 10);
	g_object_set (window, "window-position", GTK_WIN_POS_CENTER, NULL);
	gtk_window_set_default_size (window, 400, 100);
	g_signal_connect ((GtkWidget*) window, "destroy", (GCallback) _gtk_main_quit_gtk_widget_destroy, NULL);
	_data1_->i = 0;
	_tmp1_ = (GtkButton*) gtk_button_new_with_label ("Click me!");
	g_object_ref_sink (_tmp1_);
	_data1_->button = _tmp1_;
	g_signal_connect_data (_data1_->button, "clicked", (GCallback) ___lambda2__gtk_button_clicked, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
	gtk_container_add ((GtkContainer*) window, (GtkWidget*) _data1_->button);
	gtk_widget_show_all ((GtkWidget*) window);
	gtk_main ();
	result = 0;
	_g_object_unref0 (window);
	block1_data_unref (_data1_);
	_data1_ = NULL;
	return result;
}


int main (int argc, char ** argv) {
	g_type_init ();
	return _vala_main (argv, argc);
}



