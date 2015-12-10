/*****************************************************
	^> File Name: destroy.c
	^> Author: AoEiuV020
	^> Mail: 490674483@qq.com
	^> Created Time: 2015/11/12 - 22:21:57
****************************************************/
#include <gtk/gtk.h>
void destroy(GtkWidget *widget,gpointer data)
{
	g_print("destroy,\n");
    gtk_main_quit ();
}
gint delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
	static int i=3;
	GtkWindow *window=(GtkWindow*)data;
	GtkWidget *dialog;
	dialog=gtk_dialog_new_with_buttons("真要退出?",window,GTK_DIALOG_DESTROY_WITH_PARENT,"YES",GTK_RESPONSE_ACCEPT,"NO",GTK_RESPONSE_REJECT,NULL);
	g_print("delete_event,%d,\n",i);
	if(GTK_RESPONSE_ACCEPT==gtk_dialog_run((GTK_DIALOG(dialog)))&&!--i)
	{
		gtk_widget_destroy(dialog);
		return FALSE;
	}
	gtk_widget_destroy(dialog);
	return TRUE;
}
/* 没用， */
gint destroy_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
	static int i=3;
	g_print("destroy_event,%d,\n",i);
	return --i?TRUE:FALSE;
}
int main(int argc, char **argv)
{
	GtkWidget *window;
	gtk_init(&argc,&argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(delete_event),window);
	g_signal_connect(G_OBJECT(window),"destroy_event",G_CALLBACK(delete_event),NULL);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(destroy),NULL);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}
