module;

#include <gtkmm/button.h>

export module window:toggle;

import std;

export namespace app {

struct Props {
    std::function<void()> toggle;
};

class Toggle : public Gtk::Button {
public:
    Toggle(Props props);

private:
    Props props_;
};

Toggle::Toggle(Props props)
    : props_ { std::move(props) }
{
    signal_clicked().connect(props_.toggle);
    set_name("toggle");
}

}
