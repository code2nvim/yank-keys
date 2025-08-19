module;

export module input:name;

import std;

namespace app {

export auto btn_name(std::string name) -> std::string
{
    return name.replace(name.find("BTN_"), 4, "");
}

export auto key_name(std::string name) -> std::string
{
    return name.replace(name.find("KEY_"), 4, "");
}

}
