module;

export module input:name;

import std;

export namespace app {

auto btn_name(std::string name) -> std::string
{
    name.replace(name.find("BTN_"), 4, "");
    return name;
}

auto key_name(std::string name) -> std::string
{
    name.replace(name.find("KEY_"), 4, "");
    return name;
}

}
