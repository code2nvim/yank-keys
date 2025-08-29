module;

export module data:helper;

namespace app {

export template <typename... Ts>
struct Match : Ts... {
    using Ts::operator()...;
};

}
