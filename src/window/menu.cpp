module;

#include <gtkmm/window.h>

export module window:menu;

import :cfg;

namespace app {

export class Menu : public Gtk::Window {
public:
    Menu();

    void toggle();
};

Menu::Menu()
{
    set_name(app::cfg::menu.name);
    set_default_size(app::cfg::menu.width, app::cfg::menu.height);
    set_resizable(app::cfg::menu.resizable);
    signal_close_request().connect([] { return true; }, false); // unclosable util the main window is closed
}

void Menu::toggle()
{
    set_visible(!get_visible());
}

}
