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
    Gtk::StyleProvider::add_provider_for_display(
        get_display(),
        [] {
            auto css = Gtk::CssProvider::create();
            css->load_from_path(app::cfg::styles.provider);
            return css;
        }(),
        priority // clang-format
    );
    set_title(app::cfg::window.title);
    set_default_size(app::cfg::window.width, app::cfg::menu.height);
    set_resizable(app::cfg::window.resizable);
    set_child(toggle_);
    signal_close_request().connect([] { std::exit(0); return false; }, false); // exit program when window is closed
}

void Window::input()
{
    for (auto [hold, key] : app::input()) {
        if (running_) {
            toggle_.set_label(std::move(key));
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
