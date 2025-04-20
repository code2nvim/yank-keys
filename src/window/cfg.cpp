module;

#include <glibmm/refptr.h>
#include <gtkmm/cssprovider.h>

export module window:cfg;

namespace app {

export const struct {
    const char* title = "YANK - Yank A Nonsense Key";
    int width = 800;
    int height = 600;
    bool resizable = false;
} window;

export const struct {
    const char* title = "YANK - Yank A Nonsense Key (Menu)";
    int width = 300;
    int height = 300;
    bool resizable = false;
} menu;

export const struct {
    Glib::RefPtr<Gtk::CssProvider> provider = [] {
        auto tmp = Gtk::CssProvider::create();
        tmp->load_from_string("button { font-family: Monospace; font-size: 8rem; }");
        return tmp;
    }();
} toggle;

}
