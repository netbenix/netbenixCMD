#ifndef _TEST_GTK_H_
#define _TEST_GTK_H_
#include <gtk/gtk.h>

void createGTKTestWindow();
void on_button1_clicked(GtkButton *b);
void on_gay_check_toggled(GtkToggleButton *t);
void on_window_focus_out_event(GtkWindow *w);
void on_window_focus_in_event(GtkWindow *w);
void setBarLevel();
#endif