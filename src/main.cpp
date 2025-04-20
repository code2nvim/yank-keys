import window;

#include <gtkmm/application.h>

auto main(int argc, char* argv[]) -> int
{
    auto app = Gtk::Application::create(""); // TODO: application_id
    return app->make_window_and_run<app::Window>(argc, argv);
}
