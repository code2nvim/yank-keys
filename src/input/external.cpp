module;

#include <fcntl.h>
#include <sys/poll.h>
#include <unistd.h>

export module input:external;

import std;

namespace {

extern "C" {
// NOLINTBEGIN
auto poll(struct pollfd* _fds, nfds_t _nfds, int _timeout) -> int;
auto open(const char* _file, int _oflag, ...) -> int;
auto close(int _fd) -> int;
// NOLINTEND
}

}

export namespace app {

using pollfd = pollfd;

auto poll(pollfd* fds) -> int
{
    return poll(fds, 1, -1);
}

auto open_restricted(const char* file, int oflag, [[maybe_unused]] void* user_data) -> int
{
    const int descriptor = open(file, oflag); // NOLINT
    if (descriptor < 0) {
        std::exit(1);
    } else {
        return descriptor;
    }
}

void close_restricted(int descriptor, [[maybe_unused]] void* user_data)
{
    close(descriptor);
}

}
