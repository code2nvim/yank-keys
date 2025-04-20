module;

#include <gtkmm/window.h>

export module window;

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
    set_title("YANK - Yank A Nonsense Key");
    set_resizable(false);
}

}
