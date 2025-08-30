module;

export module data;

import :keymap;
import :modifier;

import std;

namespace app {

export class Data {
public:
    Data();

    [[nodiscard]] auto mod() const -> app::Mod;
    [[nodiscard]] auto keys() const -> std::vector<std::string>;
    void match(bool hold, std::string_view key);

private:
    void countdown();
    void push_key(std::string key);
    void update_mod(app::Mod::Modifier mod);

    app::Mod mod_;
    std::deque<std::pair<std::string, float>> keys_;
    std::jthread task_;
    std::mutex mtx_;
};

Data::Data()
    : task_ { [this] { countdown(); } }
{
}

auto Data::mod() const -> app::Mod
{
    return mod_;
}

auto Data::keys() const -> std::vector<std::string>
{
    auto keys = keys_
        | std::views::transform([](const auto& elem) { return elem.first; })
        | std::ranges::to<std::vector>();
    return keys;
}

void Data::match(bool hold, std::string_view key)
{
    if (hold) {
        keys_.emplace_back(app::to_mapped(key), 1.0);
    } else {
        std::ranges::transform(keys_, keys_.begin(), [key = to_mapped(key)](const auto& elem) {
            if (elem.first == key && elem.second == 1.0) {
                return decltype(elem) { elem.first, 0.99 }; // NOLINT
            }
            return elem;
        });
    }
}

void Data::countdown()
{
    for (;;) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // NOLINT
        for (std::unique_lock lock { mtx_ }; auto& [key, time] : keys_) {
            time -= time < 1.0 ? 0.1 : 0.0; // NOLINT
            std::erase_if(keys_, [key](const auto& elem) {
                return elem.first == app::to_mapped(key) && elem.second <= 0.0;
            });
        }
    }
}

void Data::update_mod(app::Mod::Modifier mod)
{
    mod_.hold(mod);
}

}
