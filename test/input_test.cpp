module;

#include <boost/test/unit_test.hpp>

module input;

import :memory;

BOOST_AUTO_TEST_CASE(memory_test)
{
    const auto udev = app::make_udev();
    BOOST_TEST(udev != nullptr);
}
