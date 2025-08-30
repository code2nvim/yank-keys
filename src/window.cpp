module;

#include "gtkmm/cssprovider.h"
#include "gtkmm/styleprovider.h"
#include <gtkmm/window.h>

export module window;

import :bottom;
import :cfg;
import :menu;
import :toggle;

import data;
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
    app::Bottom bottom_;

    app::Data data_;
    std::atomic<bool> running_ { true };
    std::jthread input_ { [this] { input(); } };
    std::mutex mtx_;
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
        priority);
    set_title(app::cfg::window.title);
    set_default_size(app::cfg::window.width, app::cfg::menu.height);
    set_resizable(app::cfg::window.resizable);
    set_child(bottom_);
    set_child(toggle_);
    signal_close_request().connect([] { std::exit(0); return false; }, false); // exit program when window is closed
}

void Window::input()
{
    std::jthread task { [this] { // update even with no input
        for (;; std::this_thread::sleep_for(std::chrono::milliseconds(100))) { // NOLINT
            std::unique_lock lock { mtx_ };
            auto joined = data_.keys() | std::ranges::views::join_with(' ');
            toggle_.set_label(std::string { joined.begin(), joined.end() });
        }
    } };
    for (const auto& [hold, key] : app::input()) {
        std::unique_lock lock { mtx_ };
        if (running_ && key != "...") {
            data_.match(hold, key);
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
