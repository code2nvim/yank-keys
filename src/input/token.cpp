module;

export module input:token;

import std;

export namespace app {

using RegularKey = char; // can be represented directly in text

using SpecialKey = std::string;

using Token = std::variant<RegularKey, SpecialKey>;

auto to_string(Token token) -> std::string
{
    return std::visit(
        [](const auto& key) {
            if constexpr (std::is_same_v<decltype(key), const RegularKey&>) {
                return std::format("{}", key == ' ' ? "space" : std::string { key });
            } else if constexpr (std::is_same_v<decltype(key), const SpecialKey&>) {
                return std::format("{}", key);
            }
        },
        token);
}

}
