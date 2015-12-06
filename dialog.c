/*****************************************************
	^> File Name: dialog.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/12 - 10:33:49
****************************************************/
#include <gtk/gtk.h>
int width=500,height=500;
void dialog(GtkWidget *width,GtkWindow *parent)
{
	GtkWidget *dialog;
	gint response;
	dialog=gtk_dialog_new_with_buttons("message...",parent,GTK_DIALOG_DESTROY_WITH_PARENT,"OK",GTK_RESPONSE_OK,"NO",GTK_RESPONSE_REJECT,"3",3,NULL);
	//g_signal_connect(dialog,"response",G_CALLBACK(gtk_widget_destroy),NULL);
	//gtk_window_set_default_size(GTK_WINDOW(dialog), width/2, height/2);
	//gtk_widget_show_all(dialog);
	//gtk_dialog_response(dialog,3);
	response=gtk_dialog_run(GTK_DIALOG(dialog));
	g_print("%d\n",response);
	switch(response)
	{
		case GTK_RESPONSE_OK:
			g_print("OK...");
			break;
		case GTK_RESPONSE_REJECT:
			g_print("REJECT...");
			break;
		default:
			g_print("default");
	}
	gtk_widget_destroy(dialog);
}
void print_hello(GtkWidget * widget, gpointer data)
{
	g_print("Hello World\n");

	dialog(widget,(GtkWindow*)(data));
}

static void activate(GtkApplication * app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Window");
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);

	button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add(GTK_CONTAINER(window), button_box);

	button = gtk_button_new_with_label("Hello World");
	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), window);
	//g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
	gtk_container_add(GTK_CONTAINER(button_box), button);

	gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}
