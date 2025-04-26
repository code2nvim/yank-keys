module;

#include <gtkmm/button.h>

#include <functional>
#include <utility>

export module window:toggle;

import :cfg;

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
    constexpr int priority = 800; // GTK_STYLE_PROVIDER_PRIORITY_USER is defined in <gtk/gtk.h>, which is a C header
    get_style_context()->add_provider(app::toggle.provider, priority);
    signal_clicked().connect([this] { props_.toggle(); });
}

}
