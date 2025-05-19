module;

#include <libinput.h>
#include <libudev.h>

#include <functional>
#include <memory>

export module input:memory;

export namespace app {

using udev_ptr = std::unique_ptr<udev, std::function<void(udev*)>>;

auto make_udev()
{
    return udev_ptr {
        udev_new(),
        [](udev* udev) {
            udev_unref(udev);
        },
    };
}

using libinput_ptr = std::unique_ptr<libinput, std::function<void(libinput*)>>;

auto make_libinput(const libinput_interface* interface, void* user_data, udev* udev)
{
    return libinput_ptr {
        libinput_udev_create_context(interface, user_data, udev),
        [](libinput* libinput) {
            libinput_unref(libinput);
        }
    };
}

using event_ptr = std::unique_ptr<libinput_event, std::function<void(libinput_event*)>>;

auto make_event(libinput* libinput)
{
    return event_ptr {
        libinput_get_event(libinput),
        [](libinput_event* event) {
            libinput_event_destroy(event);
        },
    };
}

}
