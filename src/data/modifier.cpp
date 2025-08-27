module;

export module data:modifier;

import :helper;

import std;

namespace app {

export class Modifier {
public:
    struct Alt { };
    struct Ctrl { };
    struct Shift { };

    using Mod = std::variant<Alt, Ctrl, Shift>;

    [[nodiscard]] auto held(Mod key) const -> bool;

private:
    int value_ = 0b000;
};

auto Modifier::held(Mod key) const -> bool
{
    return key.visit(app::overloaded(
        [this](Alt) {
            return (value_ & 0b100) != 0;
        },
        [this](Ctrl) {
            return (value_ & 0b010) != 0;
        },
        [this](Shift) {
            return (value_ & 0b001) != 0;
        }));
}

}
