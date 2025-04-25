module;

#include <gtkmm/window.h>

export module window;

import :cfg;
import :menu;
import :toggle;

export namespace app {

// main window
class Window : public Gtk::Window {
public:
    Window();

private:
    void toggle();

    app::Menu menu_;
    app::Toggle toggle_;
};

Window::Window()
{
    set_title(app::window.title);
    set_default_size(app::window.width, app::menu.height);
    set_resizable(app::window.resizable);
    set_child(toggle_);
    toggle_.signal_clicked().connect([&] { toggle(); });
}

void Window::toggle()
{
    menu_.set_visible(!menu_.get_visible());
    set_resizable(!get_resizable());
}

}
