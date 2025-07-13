module;

export module window:cfg;

export namespace app {

const struct Window_ {
    const char* title = "yank-keys";
    int width = 800;
    int height = 600;
    bool resizable = false;
} window;

const struct Menu_ {
    const char* title = "yank-keys";
    int width = 300;
    int height = 300;
    bool resizable = false;
} menu;

const struct Styles_ {
    const char* provider
        = "#toggle {"
          "  font-family: Monospace;"
          "  font-size: 6rem;"
          "}";
} styles;

}
