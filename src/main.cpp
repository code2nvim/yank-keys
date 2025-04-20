#include <gtkmm/application.h>

import window;

auto main(int argc, char* argv[]) -> int
{
    auto app = Gtk::Application::create(""); // TODO: application_id
    return app->make_window_and_run<app::Window>(argc, argv);
}
