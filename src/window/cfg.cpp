module;

export module window:cfg;

namespace app {

export constexpr struct {
    const char* title = "YANK - Yank A Nonsense Key";
    int width = 800;
    int height = 600;
    bool resizable = false;
} window;

export constexpr struct {
    const char* title = "YANK - Yank A Nonsense Key (Menu)";
    int width = 300;
    int height = 300;
    bool resizable = false;
} menu;

}
