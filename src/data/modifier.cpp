module;

export module data:modifier;

import :helper;

import std;

namespace app {

export class Mod {
public:
    struct Alt { };
    struct Ctrl { };
    struct Shift { };
    using Modifier = std::variant<Alt, Ctrl, Shift>;

    [[nodiscard]] auto held(auto... keys) const -> bool;
    [[nodiscard]] auto only(Modifier keys) const -> bool;
    void hold(Modifier key);
    void release(Modifier key);

private:
    int value_ = 0b000;
};

auto Mod::held(auto... keys) const -> bool
{
    static_assert((std::is_same_v<Modifier, decltype(keys)> && ...));
    return (keys.visit(app::Match(
                [this](Alt) { return value_ & 0b100; },
                [this](Ctrl) { return value_ & 0b010; },
                [this](Shift) { return value_ & 0b001; }))
        && ...);
}

auto Mod::only(Modifier key) const -> bool
{
    return (key.visit(app::Match(
        [this](Alt) { return (value_ & 0b100) != 0; },
        [this](Ctrl) { return (value_ & 0b010) != 0; },
        [this](Shift) { return (value_ & 0b001) != 0; })));
}

void Mod::hold(Modifier key)
{
    value_ |= key.visit(app::Match(
        [](Alt) { return 0b100; },
        [](Ctrl) { return 0b010; },
        [](Shift) { return 0b001; }));
}

void Mod::release(Modifier key)
{
    value_ &= ~key.visit(app::Match(
        [](Alt) { return 0b100; },
        [](Ctrl) { return 0b010; },
        [](Shift) { return 0b001; }));
}

}
