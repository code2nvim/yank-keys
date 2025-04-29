module;

#include <libinput.h>
#include <libudev.h>

#include <functional>
#include <memory>

export module input:ptr;

export namespace app {

auto make_udev()
{
    return std::unique_ptr<udev, std::function<void(udev*)>> {
        udev_new(),
        [](udev* udev) {
            udev_unref(udev);
        },
    };
}

auto make_libinput(const libinput_interface* interface, void* user_data, udev* udev)
{
    return std::unique_ptr<libinput, std::function<void(libinput*)>> {
        libinput_udev_create_context(interface, user_data, udev),
        [](libinput* libinput) {
            libinput_unref(libinput);
        }
    };
}

auto make_event(libinput* libinput)
{
    return std::unique_ptr<libinput_event, std::function<void(libinput_event*)>> {
        libinput_get_event(libinput),
        [](libinput_event* input) {
            libinput_event_destroy(input);
        },
    };
}

}
