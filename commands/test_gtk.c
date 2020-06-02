#include <gtk/gtk.h>

#include "../utils/logger.h"

	GtkWidget *window;
	GtkWidget *fixed1;
	GtkWidget *button1;
	GtkWidget *label;
	GtkWidget *gay_check;
	GtkWidget *level;
	GtkBuilder *builder;

void createTestWindow(){

	gtk_init(0, NULL);

	builder = gtk_builder_new_from_file("glade/test.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
	gay_check = GTK_WIDGET(gtk_builder_get_object(builder, "gay_check"));
	level = GTK_WIDGET(gtk_builder_get_object(builder, "level"));

	gtk_widget_show(window);
	gtk_main();
	logger("[GTK] Window closed.");
}

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

void on_button1_clicked(GtkButton *b){
	gtk_label_set_text(GTK_LABEL(label), (const gchar*) "DO NOT PUSH THE BUUUTTTON");
	logger("[GTK] Button 'button1' clicked.");
	setBarLevel();
}

void on_gay_check_toggled(GtkToggleButton *t){
	if(gtk_toggle_button_get_active(t)){
		gtk_label_set_text(GTK_LABEL(label), (const gchar*) "Oh hey, I'm gay now.");
		logger("[GTK] Toggle 'gay_check' changed to toggled.");
	} else {
		gtk_label_set_text(GTK_LABEL(label), (const gchar*) "Well, I'm not longer gay.");
		logger("[GTK] Toggle 'gay_check' changed to untoggled.");
	}
}

void on_window_focus_out_event(GtkWindow *w){
	gtk_label_set_text(GTK_LABEL(label), (const gchar*) "HEY! COME BACK!");
	logger("[GTK] Window focus lost.");
}

void on_window_focus_in_event(GtkWindow *w){
	gtk_label_set_text(GTK_LABEL(label), (const gchar*) "Welcome Back!");
	logger("[GTK] Window regained focus.");
}