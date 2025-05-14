module;

#include <libinput.h>

#include <generator>
#include <string>

export module input;

import :external;
import :memory;

namespace {

auto to_string(const auto& libinput) -> std::string
{
    while (auto event = app::make_event(libinput.get())) {
        switch (libinput_event_get_type(event.get())) {
        case LIBINPUT_EVENT_POINTER_BUTTON:
            return std::string { "pointer" };
        case LIBINPUT_EVENT_KEYBOARD_KEY:
            return std::string { "keyboard" };
        default:
            return std::string { "unknown" };
        }
    }
    return {};
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
    for (;;) {
        app::pollfd fds = {
            .fd = libinput_get_fd(libinput.get()),
            .events = 0x001,
            .revents = 0,
        };
        app::poll(&fds);
        libinput_dispatch(libinput.get());
        co_yield to_string(libinput);
    }
}

}
