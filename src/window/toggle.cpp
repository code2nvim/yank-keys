module;

#include <gtkmm/button.h>

export module window:toggle;

import :cfg;

export namespace app {

class Toggle : public Gtk::Button {
public:
    Toggle();
};

Toggle::Toggle()
{
    constexpr int priority = 800; // GTK_STYLE_PROVIDER_PRIORITY_USER is defined in <gtk/gtk.h>, which is a C header
    get_style_context()->add_provider(app::toggle.provider, priority);
}

}
