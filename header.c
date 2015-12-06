/*****************************************************
	^> File Name: header.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/12 - 13:56:35
****************************************************/
#include <gtk/gtk.h>
int width=500,height=500;
static void print_hello(GtkWidget * widget, gpointer data)
{
	g_print("Hello World\n");
}

static void activate(GtkApplication * app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *header;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Window");
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);

	header = gtk_header_bar_new();
	gtk_header_bar_set_title(header,"head...");
	gtk_container_add(GTK_CONTAINER(window), header);

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
