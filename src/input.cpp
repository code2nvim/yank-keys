module;

#include <libinput.h>

#include <generator>
#include <print>
#include <string>

export module input;

import :event;
import :external;
import :memory;

namespace {

auto to_string(const app::event_ptr& event) -> std::string
{
    switch (libinput_event_get_type(event.get())) {
    case LIBINPUT_EVENT_KEYBOARD_KEY:
        return app::keyboard_event(event);
    case LIBINPUT_EVENT_POINTER_BUTTON:
        return app::pointer_event(event);
    default:
        return "unknown";
    }
}

}

export namespace app {

auto input() -> std::generator<std::string>
{
    const auto udev = app::make_udev();
    const libinput_interface interface = {
        .open_restricted = app::open_restricted,
        .close_restricted = app::close_restricted,
    };
    const auto libinput = app::make_libinput(&interface, nullptr, udev.get());
    libinput_udev_assign_seat(libinput.get(), "seat0");
    app::pollfd fds = {
        .fd = libinput_get_fd(libinput.get()),
        .events = 0x001, // POLLIN from <poll.h>
        .revents = 0,
    };
    for (;;) {
        app::poll(&fds);
        libinput_dispatch(libinput.get());
        while (auto event = app::make_event(libinput.get())) {
            co_yield std::string { to_string(event) };
        }
    }
}

}
