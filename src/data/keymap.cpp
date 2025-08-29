module;

export module data:keymap;

import :modifier;

import std;

namespace app {

export const std::unordered_map<std::string_view, std::string_view> keymap {
    // modifier
    { "KEY_LEFTALT", "L⎇" },
    { "KEY_LEFTCTRL", "L⎈" },
    { "KEY_LEFTSHIFT", "L⇧" },
    { "KEY_RIGHTALT", "R⎇" },
    { "KEY_RIGHTCTRL", "R⎈" },
    { "KEY_RIGHTSHIFT", "R⇧" },
    { "KEY_RIGHTMETA", "❖" }, // { "KEY_RIGHTMETA", "🐧" }, // :)
    // arrow key
    { "KEY_LEFT", "←" },
    { "KEY_UP", "↑" },
    { "KEY_RIGHT", "→" },
    { "KEY_DOWN", "↓" },
    // mouse button
    { "BTN_LEFT", "🖱️1" },
    { "BTN_RIGHT", "🖱️2" },
    { "BTN_MIDDLE", "🖱️3" },
    { "BTN_EXTRA", "🖱️4" },
    { "BTN_SIDE", "🖱️5" },
    // ...
    { "KEY_BACKSPACE", "⌫" },
    { "KEY_COMPOSE", "⎄" },
    { "KEY_ENTER", "↵" },
    { "KEY_SPACE", "␣" },
    { "KEY_TAB", "↹" },
};

}
