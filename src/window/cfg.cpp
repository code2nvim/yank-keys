module;

export module window:cfg;

namespace app {

export const struct Window_ {
    const char* title = "yank-keys";
    int width = 800;
    int height = 600;
    bool resizable = false;
} window;

export const struct Menu_ {
    const char* title = "yank-keys";
    int width = 300;
    int height = 300;
    bool resizable = false;
} menu;

export const struct Styles_ {
    const char* provider = "styles.css";
} styles;

}
