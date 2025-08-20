module;

#include "gtkmm/cssprovider.h"
#include "gtkmm/styleprovider.h"
#include <gtkmm/window.h>

export module window;

import :cfg;
import :menu;
import :toggle;

import input;

import std;

namespace app {

// main window
export class Window : public Gtk::Window {
public:
    Window();

private:
    void input();
    void toggle();

    app::Menu menu_;
    app::Toggle toggle_ { { .toggle = [this] { toggle(); } } };

    std::atomic<bool> running_ { true };
    std::jthread input_ { [this] { input(); } };
};

Window::Window()
{
    constexpr int priority = 800; // GTK_STYLE_PROVIDER_PRIORITY_USER from <gtk/gtk.h>
    auto css = Gtk::CssProvider::create();
    css->load_from_path(app::styles.provider);
    Gtk::StyleProvider::add_provider_for_display(get_display(), css, priority);
    set_title(app::window.title);
    set_default_size(app::window.width, app::menu.height);
    set_resizable(app::window.resizable);
    signal_close_request().connect([] { std::exit(0); return false; }, false); // exit program when window is closed
    set_child(toggle_);
}

void Window::input()
{
    for (auto [mod, msg] : app::input()) {
        if (running_) {
            toggle_.set_label(std::move(msg));
        }
    }
}

void Window::toggle()
{
    running_ = !running_;
    set_resizable(!get_resizable());
    menu_.toggle();
}

}
