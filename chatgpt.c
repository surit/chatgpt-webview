#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

static void destroyWindowCb(GtkWidget* widget, GtkWidget* window) {
    gtk_main_quit();
}

int main(int argc, char** argv) {
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ChatGPT (webview)");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);

    // Create the webview widget
    WebKitWebView* webview = WEBKIT_WEB_VIEW(webkit_web_view_new());

    // Load the website
    webkit_web_view_load_uri(webview, "https://chat.openai.com/chat");

    // Add the webview to the window
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(webview));

    // Connect the destroy signal
    g_signal_connect(window, "destroy", G_CALLBACK(destroyWindowCb), NULL);

    // Show the window and start the main loop
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
