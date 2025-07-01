module;

export module window:cfg;

namespace app {

export const struct {
    const char* title = "yank-keys";
    int width = 800;
    int height = 600;
    bool resizable = false;
} window;

export const struct {
    const char* title = "yank-keys";
    int width = 300;
    int height = 300;
    bool resizable = false;
} menu;

export const struct {
    const char* provider
        = "#toggle {"
          "  font-family: Monospace;"
          "  font-size: 6rem;"
          "}";
} styles;

}
