#include <gtkmm/application.h>
#include <gtkmm/window.h>

auto main(int argc, char* argv[]) -> int
{
    auto app = Gtk::Application::create("TODO: application_id");
    return app->make_window_and_run<Gtk::Window>(argc, argv);
}
