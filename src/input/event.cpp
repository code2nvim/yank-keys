module;

#include <libevdev/libevdev.h>
#include <libinput.h>

#include <format>
#include <print>
#include <string>
#include <string_view>

export module input:event;

import :memory;

export namespace app {

auto keyboard_event(const app::event_ptr& event) -> std::string
{
    auto* keyboard = libinput_event_get_keyboard_event(event.get());
    const std::string_view name {
        libevdev_event_code_get_name(0x01, // EV_KEY <linux/input-event-codes.h>
            libinput_event_keyboard_get_key(keyboard)),
    };
    switch (libinput_event_keyboard_get_key_state(keyboard)) {
    case LIBINPUT_KEY_STATE_PRESSED:
        return std::format("pressed: {}", name.data());
    case LIBINPUT_KEY_STATE_RELEASED:
        return std::format("released: {}", name.data());
    };
}

}
