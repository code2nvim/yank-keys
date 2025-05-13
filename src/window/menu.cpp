module;

#include <gtkmm/window.h>

export module window:menu;

import :cfg;

export namespace app {

class Menu : public Gtk::Window {
public:
    Menu();

    void toggle();
};

Menu::Menu()
{
    set_title(app::menu.title);
    set_default_size(app::menu.width, app::menu.height);
    set_resizable(app::menu.resizable);
    signal_close_request().connect([] { return true; }, false); // unclosable util the main window is closed
}

void Menu::toggle()
{
    set_visible(!get_visible());
}

}
