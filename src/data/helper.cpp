module;

export module data:helper;

namespace app {

export template <typename... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

}
