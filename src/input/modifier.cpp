module;

#include <concepts>

export module input:modifier;

export namespace app {

namespace mod {
    struct Alt { };
    struct Ctrl { };
    struct Shift { };

    template <typename T>
    concept ModKey = std::same_as<T, mod::Alt> || std::same_as<T, mod::Ctrl> || std::same_as<T, mod::Shift>;
}

class Modifier {
public:
    [[nodiscard]] auto held(mod::ModKey auto key) const -> bool;

private:
    int value_ = 0b000;
};

auto Modifier::held(mod::ModKey auto key) const -> bool
{
    if constexpr (std::same_as<decltype(key), mod::Alt>) {
        return (value_ & 0b100) != 0;
    }
    if constexpr (std::same_as<decltype(key), mod::Ctrl>) {
        return (value_ & 0b010) != 0;
    }
    if constexpr (std::same_as<decltype(key), mod::Shift>) {
        return (value_ & 0b001) != 0;
    }
}

}
