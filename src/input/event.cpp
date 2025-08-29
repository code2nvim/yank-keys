module;

#include <libevdev/libevdev.h>
#include <libinput.h>

export module input:event;

import :memory;

import std;

namespace app {

export auto keyboard_event(const app::event_ptr& event) -> std::pair<bool, std::string>
{
    auto* keyboard = libinput_event_get_keyboard_event(event.get());
    const std::string name {
        libevdev_event_code_get_name(0x01, // EV_KEY <linux/input-event-codes.h>
            libinput_event_keyboard_get_key(keyboard)),
    };
    switch (libinput_event_keyboard_get_key_state(keyboard)) {
    case LIBINPUT_KEY_STATE_PRESSED:
        return std::tuple { true, name };
    case LIBINPUT_KEY_STATE_RELEASED:
        return std::tuple { false, name };
    };
}

export auto pointer_event(const app::event_ptr& event) -> std::pair<bool, std::string>
{
    auto* pointer = libinput_event_get_pointer_event(event.get());
    const std::string name {
        libevdev_event_code_get_name(0x01, // EV_KEY <linux/input-event-codes.h>
            libinput_event_pointer_get_button(pointer)),
    };
    switch (libinput_event_pointer_get_button_state(pointer)) {
    case LIBINPUT_BUTTON_STATE_PRESSED:
        return std::tuple { true, name };
    case LIBINPUT_BUTTON_STATE_RELEASED:
        return std::tuple { false, name };
    };
}

}
