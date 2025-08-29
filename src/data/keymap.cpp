module;

export module data:keymap;

import :modifier;

import std;

namespace app {

export const std::unordered_map<std::string_view, std::string_view> keymap {
    // arrow key
    { "KEY_LEFT", "←" },
    { "KEY_UP", "↑" },
    { "KEY_RIGHT", "→" },
    { "KEY_DOWN", "↓" },

    // charactor (base)
    { "KEY_GRAVE", "`" },
    { "KEY_MINUS", "-" },
    { "KEY_EQUAL", "=" },
    { "KEY_LEFTBRACE", "[" },
    { "KEY_RIGHTBRACE", "]" },
    { "KEY_BACKSLASH", "\\" },
    { "KEY_SEMICOLON", ";" },
    { "KEY_APOSTROPHE", "'" },
    { "KEY_COMMA", "," },
    { "KEY_DOT", "." },
    { "KEY_SLASH", "/" },

    // modifier
    { "KEY_LEFTALT", "⎇" },
    { "KEY_LEFTCTRL", "^" },
    { "KEY_LEFTSHIFT", "⇧" },
    { "KEY_RIGHTALT", "⎇" },
    { "KEY_RIGHTCTRL", "^" },
    { "KEY_RIGHTSHIFT", "⇧" },
    { "KEY_LEFTMETA", "❖" }, // { "KEY_LEFTMETA", "🐧" }, // :)

    // mouse button
    { "BTN_LEFT", "🖱️1" },
    { "BTN_RIGHT", "🖱️2" },
    { "BTN_MIDDLE", "🖱️3" },
    { "BTN_EXTRA", "🖱️4" },
    { "BTN_SIDE", "🖱️5" },

    // ...
    { "KEY_BACKSPACE", "⌫" },
    { "KEY_CAPSLOCK", "⇪" },
    { "KEY_COMPOSE", "⎄" },
    { "KEY_ENTER", "↵" },
    { "KEY_ESC", "⎋" },
    { "KEY_SPACE", "␣" },
    { "KEY_TAB", "↹" },

    { "KEY_SYSRQ", "PtrSr" },
    { "KEY_SCROLLLOCK", "ScrLk" },
    { "KEY_PAUSE", "Pause" },
    { "KEY_INSERT", "Ins" },
    { "KEY_DELETE", "Del" },
    { "KEY_HOME", "Home" },
    { "KEY_END", "End" },
    { "KEY_PAGEUP", "PgUp" },
    { "KEY_PAGEDOWN", "PgDn" },
};

/*
export const std::unordered_map<std::string_view, std::string_view> mod_map {
    // modifier
    { "⎇L", "⎇" },
    { "^L", "^" },
    { "⇧L", "⇧" },
    { "⎇R", "⎇" },
    { "^R", "^" },
    { "⇧R", "⇧" },
};
*/

export auto to_mapped(std::string_view key) -> std::string
{
    auto trim = [](std::string_view key) {
        return key.contains("KEY_") ? key.substr(4) : key;
    };
    return std::string {
        trim(keymap.contains(key) ? app::keymap.at(key) : key),
    };
}

}
