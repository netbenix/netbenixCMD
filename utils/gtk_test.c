#include <gtk/gtk.h>

#include "gtk_test.h"
#include "logger.h"

	GtkWidget *window;
	GtkWidget *fixed1;
	GtkWidget *button1;
	GtkWidget *label;
	GtkWidget *check;
	GtkWidget *level;
	GtkBuilder *builder;

void createGTKTestWindow(){

	gtk_init(0, NULL); //Init

	builder = gtk_builder_new_from_file("glade/test_window.glade"); //Set builder
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window")); //Tell the window what to build
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); //Connect destroy signal
	gtk_builder_connect_signals(builder, NULL); //Connect the signals to builder

	//Init the widgets
	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
	check = GTK_WIDGET(gtk_builder_get_object(builder, "check"));
	level = GTK_WIDGET(gtk_builder_get_object(builder, "level"));

	gtk_widget_show(window); //Show the widgets
	gtk_main(); //Create window
	logger("[GTK] Window closed.");
}

//Set the level of the bar
void setBarLevel(){
	if(gtk_level_bar_get_value(GTK_LEVEL_BAR(level)) == 100){
		gtk_label_set_text(GTK_LABEL(label), (const gchar*) "LEVEL UP!");
		logger("[GTK] LevelBar reached 100.");
		gtk_level_bar_set_value(GTK_LEVEL_BAR(level), 0);
		logger("[GTK] LevelBar reset to 0.");
	} else {
		char buffer[1024];
		gtk_level_bar_set_value(GTK_LEVEL_BAR(level), gtk_level_bar_get_value(GTK_LEVEL_BAR(level)) + 20);
		snprintf(buffer, sizeof(buffer), "[GTK] LevelBar reached %f", gtk_level_bar_get_value(GTK_LEVEL_BAR(level)));
		logger(buffer);
	}
}

//Button event
void on_button1_clicked(GtkButton *b){
	gtk_label_set_text(GTK_LABEL(label), (const gchar*) "DO NOT PUSH THE BUUUTTTON");
	logger("[GTK] Button 'button1' clicked.");
	setBarLevel();
}

void on_gay_check_toggled(GtkToggleButton *t){
	if(gtk_toggle_button_get_active(t)){
		gtk_label_set_text(GTK_LABEL(label), (const gchar*) "Toggle checked.");
		logger("[GTK] Toggle 'check' changed to toggled.");
	} else {
		gtk_label_set_text(GTK_LABEL(label), (const gchar*) "Toggle unchecked.");
		logger("[GTK] Toggle 'check' changed to untoggled.");
	}
}

//Window-focus-loss event
void on_window_focus_out_event(GtkWindow *w){
	gtk_label_set_text(GTK_LABEL(label), (const gchar*) "HEY! COME BACK!");
	logger("[GTK] Window focus lost.");
}

//Windows-focus-regain event
void on_window_focus_in_event(GtkWindow *w){
	gtk_label_set_text(GTK_LABEL(label), (const gchar*) "Welcome Back!");
	logger("[GTK] Window regained focus.");
}