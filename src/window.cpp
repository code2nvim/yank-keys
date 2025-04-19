module;

#include "gtkmm/window.h"

export module window;

export namespace app {

class Window : public Gtk::Window {
public:
    Window()
    {
        set_title("YANK - Yank A Nonsense Key");
    }
};

}
