module;

#include <gtkmm/window.h>

export module window;

import :cfg;
import :menu;

export namespace app {

// main window
class Window : public Gtk::Window {
public:
    Window();

private:
    app::Menu _menu;
};

Window::Window()
{
    set_title(app::window.title);
    set_default_size(app::window.width, app::menu.height);
    set_resizable(app::window.resizable);
}

}
