module;

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
    set_title(app::window.title);
    set_default_size(app::window.width, app::menu.height);
    set_resizable(app::window.resizable);
    signal_close_request().connect([] { std::exit(0); return false; }, false); // exit program when window is closed
    set_child(toggle_);
}

void Window::input()
{
    std::println("Window::input");
    for (auto elem : app::input()) {
        if (running_) {
            std::println("{}", elem);
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
