module;

#include <gtkmm/window.h>

export module window:menu;

export namespace app {

class Menu : public Gtk::Window {
public:
    Menu();
};

Menu::Menu()
{
    show();
    signal_close_request().connect([] { return true; }, false); // unclosable util the main window is closed
}

}
