module;

export module data;

import :keymap;
import :modifier;

import std;

namespace app {

export class Data {
public:
    [[nodiscard]] auto mod() const -> app::Mod;
    [[nodiscard]] auto keys() const -> std::deque<std::string>;
    void match(bool hold, std::string_view key);

private:
    void push_key(std::string key);
    void update_mod(app::Mod::Modifier mod);

    app::Mod mod_;
    std::deque<std::string> keys_;
};

auto Data::mod() const -> app::Mod
{
    return mod_;
}

auto Data::keys() const -> std::deque<std::string>
{
    return keys_;
}

void Data::push_key(std::string key)
{
    keys_.push_back(std::move(key));
}

void Data::update_mod(app::Mod::Modifier mod)
{
    mod_.hold(mod);
}

void Data::match(bool hold, std::string_view key)
{
    if (hold) {
        push_key(app::to_mapped(key));
    } else {
        std::erase(keys_, app::to_mapped(key));
    }
}

}
