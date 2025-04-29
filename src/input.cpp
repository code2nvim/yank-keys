module;

#include <generator>
#include <string>

export module input;

namespace {

auto to_string() -> std::string
{
    return std::string { "TODO" };
}

}

export namespace app {

auto input() -> std::generator<std::string>
{
    co_yield to_string();
}

}
