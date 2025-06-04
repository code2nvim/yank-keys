module;

#include "gtkmm/styleprovider.h"
#include <gtkmm/window.h>

#include <atomic>
#include <cstdlib>
#include <print>
#include <thread>

export module window;

import :cfg;
import :menu;
import :toggle;

import input;

export namespace app {

// main window
class Window : public Gtk::Window {
public:
    Window();

private:
    void input();
    void toggle();

    app::Menu menu_;
    app::Toggle toggle_ { ToggleProps { .toggle = [this] { toggle(); } } };

    std::atomic<bool> running_ { true };
    std::jthread input_ { [this] { input(); } };
};

Window::Window()
{
    constexpr int priority = 800; // GTK_STYLE_PROVIDER_PRIORITY_USER from <gtk/gtk.h>
    Gtk::StyleProvider::add_provider_for_display(get_display(), app::styles.provider, priority);
    set_title(app::window.title);
    set_default_size(app::window.width, app::menu.height);
    set_resizable(app::window.resizable);
    signal_close_request().connect([] { std::exit(0); return false; }, false); // exit program when window is closed
    set_child(toggle_);
}

void Window::input()
{
    std::println("Window::input");
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
