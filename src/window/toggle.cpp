module;

#include <gtkmm/button.h>

export module window:toggle;

import std;

export namespace app {

struct ToggleProps {
    std::function<void()> toggle;
};

class Toggle : public Gtk::Button {
public:
    Toggle(ToggleProps props);

private:
    ToggleProps props_;
};

Toggle::Toggle(ToggleProps props)
    : props_ { std::move(props) }
{
    signal_clicked().connect(props_.toggle);
    add_css_class("Button");
}

}
