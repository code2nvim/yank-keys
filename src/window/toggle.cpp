module;

#include <gtkmm/button.h>

#include <functional>
#include <utility>

export module window:toggle;

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
