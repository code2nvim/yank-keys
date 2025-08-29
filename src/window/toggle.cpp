module;

#include <gtkmm/button.h>

export module window:toggle;

import :cfg;

import std;

namespace app {

struct ToggleProps {
    std::function<void()> toggle;
};

export class Toggle : public Gtk::Button {
public:
    Toggle(ToggleProps props);

private:
    ToggleProps props_;
};

Toggle::Toggle(ToggleProps props)
    : props_ { std::move(props) }
{
    set_name(app::cfg::toggle.name);
    signal_clicked().connect(props_.toggle);
}

}
