module;

#include <libinput.h>

#include <generator>
#include <print>
#include <string>
#include <string_view>

export module input;

import :external;
import :memory;

namespace {

auto to_string(const app::event_ptr& event) -> std::string_view
{
    switch (libinput_event_get_type(event.get())) {
    case LIBINPUT_EVENT_POINTER_BUTTON:
        return "pointer";
    case LIBINPUT_EVENT_KEYBOARD_KEY:
        return "keyboard";
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
        .events = 0x001,
        .revents = 0,
    };
    for (;;) {
        app::poll(&fds);
        libinput_dispatch(libinput.get());
        while (auto event = app::make_event(libinput.get())) {
            if (auto elem = to_string(event); elem != "unknown") {
                co_yield std::string { elem };
            }
        }
    }
}

}
